/**
 ******************************************************************************
 * @file    main.c
 * @author  MCD Application Team
 * @version V1.0.0
 * @date    31-October-2011
 * @brief   Main program body
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; Portions COPYRIGHT 2011 STMicroelectronics</center></h2>
 ******************************************************************************
 */
/**
 ******************************************************************************
 * <h2><center>&copy; Portions COPYRIGHT 2012 Embest Tech. Co., Ltd.</center></h2>
 * @file    main.c
 * @author  CMP Team
 * @version V1.0.0
 * @date    28-December-2012
 * @brief   Main program body
 *          Modified to support the STM32F4DISCOVERY, STM32F4DIS-BB and
 *          STM32F4DIS-LCD modules.
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, Embest SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
 * OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4x7_eth.h"
#include "netconf.h"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "tcpip.h"
#include <string.h>
#include <stdlib.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/*--------------- LCD Messages ---------------*/
#define MESSAGE1   "        eeee        "
#define MESSAGE2   "  STM32F-4 Series   "
#define MESSAGE3   " UDP/TCP EchoServer "
#define MESSAGE4   "                    "

/*--------------- Tasks Priority -------------*/
#define DHCP_TASK_PRIO   ( tskIDLE_PRIORITY + 2 )      
#define LED_TASK_PRIO    ( tskIDLE_PRIORITY + 1 )

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern struct netif xnetif;
__IO uint32_t test;

/* Private function prototypes -----------------------------------------------*/
void LCD_LED_Init(void);
extern void tcpecho_init(void);
extern void udpecho_init(void);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Toggle Led4 task
 * @param  pvParameters not used
 * @retval None
 */
volatile int TTime = 0;
void ToggleLed4(void * pvParameters)
{
	while (1)
	{
		test = xnetif.ip_addr.addr;
		/*check if IP address assigned*/
		if (test != 0)
		{
			for (;;)
			{
				/* toggle LED4 each 250ms */
				STM_EVAL_LEDToggle(LED4);
				++TTime;
				if (TTime > 100)
					TTime = 0;
				vTaskDelay(100);
			}
		}
	}
}

static struct ip_addr Address;
static struct netbuf *UDPbuffer;
static struct netconn *Connection;
static unsigned short Port;
ADC_InitTypeDef ADC_InitStruct;
GPIO_InitTypeDef GPIO_InitStruct;
extern NVIC_InitTypeDef NVIC_InitStructure;
volatile Point dane[330];

int UDPsetup_network()
{
	err_t err;

	Connection = netconn_new(NETCONN_UDP);
	if (Connection != NULL)
	{
		err = netconn_bind(Connection, IP_ADDR_ANY, 7);
		if (err == ERR_OK)
		{
			UDPbuffer = netbuf_new();
			IP4_ADDR(&Address, 192, 168, 0, 1);
			Port = 7;
			return 1;
		}
	}
	//UDPbuffer = netbuf_new();
	return 0;
}

void UDPsend_packet(void * data, u16_t len)
{
	netconn_connect(Connection, &Address, Port);
	netbuf_ref(UDPbuffer, data, len);
	netconn_send(Connection, UDPbuffer);
//	nettcon_disconnect(Connection);
}
void UDPreceive_packet(void * destination, u16_t len)
{
	UDPbuffer = netconn_recv(Connection);
	netbuf_copy(UDPbuffer, destination, len);
	netbuf_delete(UDPbuffer);
}

typedef struct
{
	u32_t len;
	u8_t tab[320];
} Cluster;

//void MainTask(void * pvParameters)
//{
//	int i = 0;
//	Cluster points;
//	UDPsetup_network();
//	for (i = 0; i < 320; ++i)
//	{
//		dane[i].X = i;
//	}
//	LCD_Clear(Black);
//	while (1)
//	{
//		/*UDPbuffer = netconn_recv(Connection);
//		netbuf_copy(UDPbuffer, &points, 324);
//		netbuf_delete(UDPbuffer);*/
//		UDPreceive_packet(&points, 324);
//		for (i = 0; i < 320; ++i)
//			dane[i].Y = points.tab[i];
//		LCD_Clear(Black);
//		LCD_PolyLine(dane, 320);
//	}
//
//	LCD_Clear(Black);
//
//}
volatile u16_t adcMeasurements[300];
volatile u16_t num = 0; 
volatile u8_t aaaaaa = 0;
//xSemaphoreHandle xSemaphore;

void ADC_IRQHandler()
{
	//static signed portBASE_TYPE xHigherPriorityTaskWoken; 
	if( ADC_GetITStatus(ADC1, ADC_IT_EOC) )
	{
		ADC_ClearITPendingBit(ADC1, ADC_IT_EOC);
		adcMeasurements[num] = ADC_GetConversionValue(ADC1);
		++num;
		if( num == 270 )
		{
			num = 0;
			aaaaaa = 1;
			//xSemaphoreGiveFromISR( xSemaphore, &xHigherPriorityTaskWoken );
		}
	}
	//portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}

void MainTask(void * pvParameters)
{
	err_t err;

	char tekst[50];
	int i = 0;
	u16_t prev = 0;
	Point dane[330];
	
	vTaskDelay(1000);
	//LWIP_UNUSED_ARG(arg);

  UDPsetup_network();
	
	//vSemaphoreCreateBinary( xSemaphore );

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*ADC_InitStruct.
	 ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	 ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	 ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConvEdge_None;
	 ADC_InitStruct.ADC_Resolution = ADC_Resolution_8b;
	 ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	 ADC_Init(ADC1, &ADC_InitStruct);*/
	ADC_DeInit();
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;	//data converted will be shifted to right
	ADC_InitStruct.ADC_Resolution = ADC_Resolution_12b;	//Input voltage is converted into a 12bit number giving a maximum value of 4096
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE; //the conversion is continuous, the input data is converted more than once
	ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None; //no trigger for conversion
	ADC_InitStruct.ADC_ScanConvMode = DISABLE; //The scan is configured in one channel
	ADC_Init(ADC1, &ADC_InitStruct); //Initialize ADC with the previous configuration
	//Enable ADC conversion
	ADC_Cmd(ADC1, ENABLE);
	//Select the channel to be read from
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_3Cycles);
	ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);






	NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStructure);
	
	
	
	LCD_Clear(Black);
	LCD_DisplayStringLine(Line0, "    wykres");
	vTaskDelay(1000);
	LCD_Clear(Black);

	for (i = 0; i < 320; ++i)
	{
		dane[i].X = i;
	}
	ADC_SoftwareStartConv(ADC1);			//Start the conversion

	

	LCD_Clear(Blue);
	LCD_DisplayStringLine(Line0,"heeeeeeeeeeeeeeeelo");
	
	
	
	while (1)
	{
		if( aaaaaa == 1 )
		{
			aaaaaa = 0;
			/*adcMeasurements[0] = adcMeasurements[1] = 0;
			adcMeasurements[2] = 1;
			adcMeasurements[3] = 0b1110;*/

			//for (i = 0; i < 270; ++i)
			{
				//while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
				//adcMeasurements[i] = ADC_GetConversionValue(ADC1);
			}
			//xSemaphoreTake(xSemaphore, 9999999);
			NVIC_DisableIRQ(ADC_IRQn);
			
			//LCD_Clear(Blue);
			//LCD_DisplayStringLine(Line0,"wyslalem");
			
			
			UDPsend_packet(adcMeasurements,540);
			
			NVIC_EnableIRQ(ADC_IRQn);
			//LCD_Clear(Black);
			//LCD_PolyLine(dane, 320);
		}
	}
}

/**
 * @brief  Main program.
 * @param  None
 * @retval None
 */
int main(void)
{
	/*!< At this stage the microcontroller clock setting is already configured to
	 144 MHz, this is done through SystemInit() function which is called from
	 startup file (startup_stm32f4xx.s) before to branch to application main.
	 To reconfigure the default setting of SystemInit() function, refer to
	 system_stm32f4xx.c file
	 */
	/*Initialize LCD and Leds */
	LCD_LED_Init();

	/* configure ethernet (GPIOs, clocks, MAC, DMA) */
	ETH_BSP_Config();

	/* Initilaize the LwIP stack */
	LwIP_Init();

	/* Initialize tcp echo server */
//tcpecho_init();
	/* Initialize udp echo server */
//udpecho_init();
//	if( ! UDPsetup_network() )
//	{
//		while(1)
//		{
//		}
//	}
	sys_thread_new("Main", MainTask, NULL, DEFAULT_THREAD_STACKSIZE,
			( tskIDLE_PRIORITY + 3));

#ifdef USE_DHCP
	/* Start DHCPClient */
	xTaskCreate(LwIP_DHCP_task, "DHCPClient", configMINIMAL_STACK_SIZE * 2, NULL,DHCP_TASK_PRIO, NULL);
#endif

	/* Start toogleLed4 task : Toggle LED4  every 250ms */
	xTaskCreate(ToggleLed4, "LED4", configMINIMAL_STACK_SIZE, NULL,
			LED_TASK_PRIO, NULL);

//xTaskCreate(MainTask, "Main", configMINIMAL_STACK_SIZE, NULL, LED_TASK_PRIO, NULL);

	/* Start scheduler */
	vTaskStartScheduler();

	/* We should never get here as control is now taken by the scheduler */
	for (;;)
		;
}

/**
 * @brief  Initializes the STM324xG-EVAL's LCD and LEDs resources.
 * @param  None
 * @retval None
 */
void LCD_LED_Init(void)
{
#ifdef USE_LCD
	/* Initialize the STM324xG-EVAL's LCD */
	STM32f4_Discovery_LCD_Init();
#endif

	STM_EVAL_LEDInit(LED4);
#ifdef USE_LCD
	/* Clear the LCD */
	LCD_Clear(Black);

	/* Set the LCD Back Color */
	LCD_SetBackColor(Black);

	/* Set the LCD Text Color */
	LCD_SetTextColor(White);

	/* Display message on the LCD*/
	LCD_DisplayStringLine(Line0, (uint8_t*) MESSAGE1);
	LCD_DisplayStringLine(Line1, (uint8_t*) MESSAGE2);
	LCD_DisplayStringLine(Line2, (uint8_t*) MESSAGE3);
	LCD_DisplayStringLine(Line3, (uint8_t*) MESSAGE4);
#endif
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *   where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{}
}
#endif

/*********** Portions COPYRIGHT 2012 Embest Tech. Co., Ltd.*****END OF FILE****/

