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

#define LED_TASK_PRIO    ( tskIDLE_PRIORITY + 1 )



ADC_InitTypeDef ADC_InitStruct;
GPIO_InitTypeDef GPIO_InitStruct;
DMA_InitTypeDef DMA_InitStruct;
extern NVIC_InitTypeDef NVIC_InitStructure;
ADC_CommonInitTypeDef ADC_CommonInitStructure;
TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
ADC_InitTypeDef       ADC_InitStructure;
ADC_CommonInitTypeDef ADC_CommonInitStructure;
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



void DMA2_Stream0_IRQHandler()
{
	DEBUG("in");
}




volatile u16_t i;
volatile u16 data[300], data2[300];
volatile u32 iii;

void MainTask(void * pvParameters)
{
	
//	UART_Setup();
//	//UDPsetup_network();
//	
//	DEBUG("a\n\r");
//	
//	for(i=0;i<270;i++) 
//	{
//		data[i] = i;
//		data2[i] = 0;
//	}		
//	
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 | RCC_AHB1Periph_GPIOA  , ENABLE);
//  
//  /* 2. Enable and configure Peripheral DMA_Stream (not required by SRAM).*/
//  
//  /* 3. For a given Stream, program the required configuration 
//  through following parameters: Source and Destination addresses, 
//  Transfer Direction, Transfer size, Source and Destination data formats, 
//  Circular or Normal mode, Stream Priority level, Source and Destination 
//  Incrementation mode, FIFO mode and its Threshold (if needed), 
//  Burst mode for Source and/or  Destination (if needed) using the DMA_Init().*/

//  DMA_DeInit(DMA2_Stream0);
//  while(DMA_GetCmdStatus(DMA2_Stream0) != DISABLE);

//   DMA_InitStructure.DMA_Channel = DMA_Channel_0;
//  DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&data);
//  DMA_InitStructure.DMA_Memory0BaseAddr = (u32)(&data);
//  DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToMemory;
//  DMA_InitStructure.DMA_BufferSize = (uint32_t) (270);
//  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
//  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
//  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
//  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
//  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
//  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
//  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
//  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
//  //DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_INC8;
//  //DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_INC8;
//  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
//  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;


//  DMA_Init(DMA2_Stream0, &DMA_InitStructure);

//  /* 4. Enable the NVIC and the corresponding interrupt(s)
//   using the function DMA_ITConfig() if you need to use DMA interrupts.*/
//  DMA_ITConfig(DMA2_Stream0, DMA_IT_TC, ENABLE);

//  /* 5. Optionally, if the Circular mode is enabled, you can use the 
//  Double buffer by configuring the second Memory address and the 
//  first Memory to be used through the function DMA_DoubleBufferModeConfig(). 
//  Then enable the Double buffer mode through the function
//  DMA_DoubleBufferModeCmd(). These operations must be done before step 6.*/

//  /* 6. Enable the DMA stream using the DMA_Cmd() function. */
//  DMA_Cmd(DMA2_Stream0, ENABLE);
		
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	iii = 0;
	while (1)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		++iii;
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
	LCD_LED_Init();
	ETH_BSP_Config();
	LwIP_Init();
	sys_thread_new("Main", MainTask, NULL, DEFAULT_THREAD_STACKSIZE,
			( tskIDLE_PRIORITY + 3));

#ifdef USE_DHCP
	/* Start DHCPClient */
	xTaskCreate(LwIP_DHCP_task, "DHCPClient", configMINIMAL_STACK_SIZE * 2, NULL,DHCP_TASK_PRIO, NULL);
#endif

	
	
	/* Start toogleLed4 task : Toggle LED4  every 250ms */
	xTaskCreate(ToggleLed4, (const signed char *)"LED4", configMINIMAL_STACK_SIZE, NULL,
			LED_TASK_PRIO, NULL);

//xTaskCreate(MainTask, "Main", configMINIMAL_STACK_SIZE, NULL, LED_TASK_PRIO, NULL);

	/* Start scheduler */
	vTaskStartScheduler();

	/* We should never get here as control is now taken by the scheduler */
	for (;;)
		;
}

