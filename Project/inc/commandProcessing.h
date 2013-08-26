//FIXME


#ifndef __COMMANDPROCESSING_H__
#define __COMMANDPROCESSING_H__

#include "arch/cc.h"
extern "C" {
#include "stm32f4x7_eth.h"
#include "netconf.h"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "tcpip.h"
#include <string.h>
#include "LCD.h"
}
#include "errorHandlers.h"
#include "sendRcvTask.h"

struct OnePacket
{
	u16_t length; //2 bytes
	char  data[560];
	void clean()
	{
		vPortFree(this);
	}
};

struct TableOf16bits
{
	u16_t length; //2 bytes
	u16_t data[280];
	void clean()
	{
		vPortFree(this);
	}
};

struct Cluster
{
	u8_t command;
	u8_t nrOfParameters;
	u16_t parameters[270];
	u8_t check_for_parameters(u8_t expected);
	void parseCommand();
};


#endif
