//FIXME


#ifndef __commandProcessing_h__
#define __commandProcessing_h__

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
#include "errorHandlers.h"
#include "sendRcvTask.h"
#include "commandProcessing.h"


void send_error_code(uint16_t code)
{
	OnePacket * response;
	response = (OnePacket *)pvPortMalloc(2+4);
	response->length = 5;
	response->data[0] = 'E';
	response->data[1] = 'R';
	response->data[2] = 'R';
	response->data[3] = code >> 8;
	response->data[4] = (code & 0xFF);
	xQueueSend(sendQueue, &response, 0);
}


#endif
