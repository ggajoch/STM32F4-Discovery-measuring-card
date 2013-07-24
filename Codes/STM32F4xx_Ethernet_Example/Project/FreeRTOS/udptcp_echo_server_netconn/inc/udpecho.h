#ifndef __UDPECHO_H__
#define __UDPECHO_H__


#include "main.h"

int UDPsetup_network(void);
void UDPsend_packet(void * data, u16_t len);
void UDPreceive_packet(void * destination, u16_t len);













#endif
