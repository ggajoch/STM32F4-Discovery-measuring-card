//FIXME
//#include "sendRcvTask.h"
#include "commandProcessing.h"
#include "arch/cc.h"
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


xSemaphoreHandle blockEthernetInterface, blockReadingTask, dataToRead, networkOK;
xQueueHandle sendQueue, receiveQueue;
struct netconn *UDPConnection;



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
