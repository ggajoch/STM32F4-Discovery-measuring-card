extern "C" {
#include "stm32f4x7_eth.h"
#include "netconf.h"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "tcpip.h"
#include <string.h>
#include <stdlib.h>
#include "udpecho.h"
#include "LCD.h"
}
#define LED_TASK_PRIO    ( tskIDLE_PRIORITY + 1 )



ADC_InitTypeDef ADC_InitStruct;
GPIO_InitTypeDef GPIO_InitStruct;
DMA_InitTypeDef DMA_InitStruct;
extern NVIC_InitTypeDef NVIC_InitStructure;
ADC_CommonInitTypeDef ADC_CommonInitStructure;
TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
ADC_InitTypeDef       ADC_InitStructure;
//ADC_CommonInitTypeDef ADC_CommonInitStructure;
DMA_InitTypeDef       DMA_InitStructure;
GPIO_InitTypeDef      GPIO_InitStructure;
USART_InitTypeDef USARTInit;
volatile Point dane[330];
DAC_InitTypeDef  DAC_InitStructure;
TIM_OCInitTypeDef  TIM_OCInitStructure;
USART_InitTypeDef USART_InitStructure;




void UART_Setup()
{
	GPIO_InitTypeDef GPIO_InitStruct; // this is for the GPIO pins used as TX and RX
	USART_InitTypeDef USART_InitStruct; // this is for the USART1 initilization
	NVIC_InitTypeDef NVIC_InitStructure; // this is used to configure the NVIC (nested vector interrupt controller)

	/* enable APB2 peripheral clock for USART1 
	 * note that only USART1 and USART6 are connected to APB2
	 * the other USARTs are connected to APB1
	 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* enable the peripheral clock for the pins used by 
	 * USART1, PB6 for TX and PB7 for RX
	 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	/* This sequence sets up the TX and RX pins 
	 * so they work correctly with the USART1 peripheral
	 */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; // Pins 6 (TX) and 7 (RX) are used
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOB, &GPIO_InitStruct);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	/* The RX and TX pins are now connected to their AF
	 * so that the USART1 can take over control of the 
	 * pins
	 */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1); //
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);

	/* Now the USART_InitStruct is used to define the 
	 * properties of USART1 
	 */
	USART_InitStruct.USART_BaudRate = 115200;				// the baudrate is set to the value we passed into this init function
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStruct.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStruct.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART1, &USART_InitStruct);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting


	/* Here the USART1 receive interrupt is enabled
	 * and the interrupt controller is configured 
	 * to jump to the USART1_IRQHandler() function
	 * if the USART1 receive interrupt occurs
	 */
	/*USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt 

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		 // we want to configure the USART1 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART1 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART1 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff	
	*/

	// finally this enables the complete USART1 peripheral
	USART_Cmd(USART1, ENABLE);
}

void putcharUsart(char x)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	USART_SendData(USART1, x);
}
void USARTPrintString(char * x)
{
	while(*x)
	{
		putcharUsart(*x);
		x++;
	}
}
#define DEBUG(x) USARTPrintString(x)



void ToggleLed4(void * pvParameters)
{
	while (1)
	{
		for (;;)
		{
			STM_EVAL_LEDToggle(LED4);
			vTaskDelay(100);
		}
	}
}

xSemaphoreHandle blockEthernetInterface = NULL, blockReadingTask = NULL, dataToRead = NULL, networkOK = NULL;
xQueueHandle sendQueue = NULL, receiveQueue = NULL;
static struct netconn *UDPConnection;

struct OnePacket
{
	u16_t length; //2 bytes
	char  data[560];
	void clean()
	{
		vPortFree(this);
	}
} ;


struct Cluster
{
	u8_t command;
	u8_t nrOfParameters;
	u32_t parameters[125];
	void parseCommand()
	{
		OnePacket * response;
		if( command == COMMAND_TEST )
		{
			//test commands
			if( nrOfParameters == 2 && parameters[0] == 2 && parameters[1] == 3 )
			{
				response = (OnePacket *)pvPortMalloc(2+2);
				response->length = 2;
				response->data[0] = 'O';
				response->data[1] = 'K';
				xQueueSend(sendQueue, &response, 0);
			}
			else
			{
				response = (OnePacket *)pvPortMalloc(2+3);
				response->length = 3;
				response->data[0] = 'E';
				response->data[1] = 'R';
				response->data[2] = 'R';
				xQueueSend(sendQueue, &response, 0);
			}
		}
	}
};

void MainTask(void * pvParameters)
{
	OnePacket x;
	OnePacket * wsk_x = &x;
	char nap[] = "aaa";
	u8_t i;

	UART_Setup();
	UDPConnection = UDPsetup_network();


	x.length = 3;
	sprintf(x.data, "aaa");
	//x.data = nap;

	xSemaphoreGive( blockReadingTask );
	xSemaphoreGive( networkOK );
	while (1)
	{
		OnePacket * wsk_packet, *ww;
		Cluster * order;
		if( xQueueReceive(receiveQueue, &wsk_packet, portMAX_DELAY) == pdTRUE)
		{
			//xQueueSend(sendQueue, &wsk_packet, 0);
			order = (Cluster *)&(wsk_packet->data[0]);
			order->parseCommand();
			wsk_packet->clean();
			
			
			
			//vPortFree(wsk_packet);
		}
	}
}




void sendingTask(void * param)
{
	OnePacket * packet;
	while( sendQueue == NULL );
	while( networkOK == NULL );
	while( xSemaphoreTake(networkOK, portMAX_DELAY) != pdTRUE );
	xSemaphoreGive( networkOK );
	while(1)
	{
		if( xQueueReceive(sendQueue, &packet, portMAX_DELAY ) == pdTRUE )
		{
			while( xSemaphoreTake( blockEthernetInterface, portMAX_DELAY ) != pdTRUE );

			UDPsend_packet(packet->data,packet->length);

			vPortFree(packet);
			xSemaphoreGive( blockEthernetInterface );
		}
	}
}



u8_t rcvBuffer[600];
static int rcvSize = 0;
void ReadingTask(void * pvParameters)
{
	OnePacket * pointer_to_packet;
	static struct netbuf *UDPbuffer;

	while( blockEthernetInterface == NULL );
	while( networkOK == NULL );
	while( xSemaphoreTake(networkOK, portMAX_DELAY) != pdTRUE );
	xSemaphoreGive( networkOK );

	while(1)
	{
		if ( xSemaphoreTake(dataToRead, portMAX_DELAY) == pdTRUE )
		{
			//pointer_to_packet = malloc(OnePacketMAXSIZE
			//rcvSize = UDPreceive_packet(rcvBuffer);
			UDPbuffer = netconn_recv(UDPConnection);
			pointer_to_packet = (OnePacket *)pvPortMalloc(2+UDPbuffer->p->tot_len);
			pointer_to_packet->length = UDPbuffer->p->tot_len;
			netbuf_copy(UDPbuffer, pointer_to_packet->data, UDPbuffer->p->tot_len);
			netbuf_delete(UDPbuffer);

			xQueueSend(receiveQueue, &pointer_to_packet, 0);
		}
	}
}



int main(void)
{
	/*!< At this stage the microcontroller clock setting is already configured to
	 144 MHz, this is done through SystemInit() function which is called from
	 startup file (startup_stm32f4xx.s) before to branch to application main.
	 To reconfigure the default setting of SystemInit() function, refer to
	 system_stm32f4xx.c file
	 */
	
	
	blockEthernetInterface = xSemaphoreCreateMutex();	
	xSemaphoreGive( blockEthernetInterface );
	
	blockReadingTask = xSemaphoreCreateMutex();	
	xSemaphoreTake( blockReadingTask, portMAX_DELAY );
	
	vSemaphoreCreateBinary(dataToRead);
	xSemaphoreTake( dataToRead, portMAX_DELAY );
	
	//networkOK = xSemaphoreCreateMutex();
	vSemaphoreCreateBinary(networkOK);
	xSemaphoreTake(networkOK, portMAX_DELAY);
	
	sendQueue = xQueueCreate(100, sizeof( OnePacket * ));
	receiveQueue = xQueueCreate(10, sizeof( OnePacket * ));
	
	
	
	
	LCD_LED_Init();
	ETH_BSP_Config();
	LwIP_Init();
	
	
	sys_thread_new("Main", MainTask, NULL, DEFAULT_THREAD_STACKSIZE,( tskIDLE_PRIORITY + 3));
	xTaskCreate(ToggleLed4, (const signed char *)"LED4", configMINIMAL_STACK_SIZE, NULL,( tskIDLE_PRIORITY + 4), NULL);
	xTaskCreate(ReadingTask, (const signed char *)"ReadingTask", DEFAULT_THREAD_STACKSIZE, NULL,( tskIDLE_PRIORITY + 4), NULL);
	xTaskCreate(sendingTask, (const signed char *)"sendingTask", DEFAULT_THREAD_STACKSIZE, NULL,( tskIDLE_PRIORITY + 3), NULL);



	/* Start scheduler */
	vTaskStartScheduler();

	/* We should never get here as control is now taken by the scheduler */
	for (;;)
		;
}

