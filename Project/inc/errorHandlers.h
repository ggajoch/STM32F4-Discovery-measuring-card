//FIXME


#ifndef __ERRORHANDLERS_H__
#define __ERRORHANDLERS_H__

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

void send_error_code(uint16_t code);

#endif
