/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */


#include "lwip/opt.h"
#include "stm32f4_discovery_lcd.h"

#if LWIP_NETCONN
#include "main.h"
#include "lwip/api.h"
#include "lwip/sys.h"


#define UDPECHO_THREAD_PRIO  ( tskIDLE_PRIORITY + 3 )


static struct ip_addr Address;
static struct netbuf *UDPbuffer;
static struct netconn *Connection;
static unsigned short Port;

extern xSemaphoreHandle dataToRead;

void giveSem(struct netconn * a, enum netconn_evt b, u16_t len)
{
	xSemaphoreGive(dataToRead);
}

int UDPsetup_network()
{
	err_t err;

	Connection = netconn_new_with_callback(NETCONN_UDP, giveSem);
	if (Connection != NULL)
	{
		err = netconn_bind(Connection, IP_ADDR_ANY, 7);
		if (err == ERR_OK)
		{
			UDPbuffer = netbuf_new();
			IP4_ADDR(&Address, 192, 168, 1, 100);
			Port = 7;
			return 1;
		}
	}
	if( netconn_connect(Connection, &Address, Port) != ERR_OK )
	{
		while(1)
		{
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
	netconn_disconnect(Connection);
}
u16_t UDPreceive_packet(void * destination)
{
	u16_t size = 0;
	UDPbuffer = netconn_recv(Connection);
	netbuf_copy(UDPbuffer, destination, UDPbuffer->p->tot_len);
	size = UDPbuffer->p->tot_len;
	netbuf_delete(UDPbuffer);
	return size;
}




 




#endif /* LWIP_NETCONN */
