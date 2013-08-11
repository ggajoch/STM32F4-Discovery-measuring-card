#ifndef __UDPECHO_H__
#define __UDPECHO_H__


#include "main.h"

struct netconn * UDPsetup_network(void);
void UDPsend_packet(void * data, u16_t len);
u16_t UDPreceive_packet(void * destination);













#endif
