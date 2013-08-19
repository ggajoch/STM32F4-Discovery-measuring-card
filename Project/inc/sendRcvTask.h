//FIXME

#ifndef __SENDRCVTASK_H__
#define __SENDRCVTASK_H__

#include "FreeRTOS.h"
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

extern xSemaphoreHandle blockEthernetInterface, blockReadingTask, dataToRead, networkOK;
extern xQueueHandle sendQueue, receiveQueue;
extern struct netconn *UDPConnection;


void ReadingTask(void * pvParameters);
void sendingTask(void * param);

#endif
