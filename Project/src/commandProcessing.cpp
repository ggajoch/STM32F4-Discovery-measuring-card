//FIXME
#include "commandProcessing.h"
#include "errorHandlers.h"
#include <inttypes.h>


u8_t Cluster::check_for_parameters(u8_t expected)
{
		if( this->nrOfParameters != expected )
		{
			send_error_code(this->nrOfParameters);
			return false;
		}
		return true;
}

void send_debug_info(char * txt)
{
	OnePacket * response;
	sprintf(response->data,"DEBUG:%s",txt);
	response->length = strlen(response->data);
	xQueueSend(sendQueue, &response, 0);
}

static u8_t xxx;
void Cluster::parseCommand()
{
	OnePacket * response;
	xxx = command;
	if( command == COMMAND_TEST )
	{
		//test commands
		if( !check_for_parameters(2) ) return;
		if( nrOfParameters == 2 && parameters[0] == 2 && parameters[1] == 3 )
		{
				OnePacket * response;
				response = (OnePacket *)pvPortMalloc(2+2);
				response->length = 2;
				response->data[0] = 'O';
				response->data[1] = 'K';
				xQueueSend(sendQueue, &response, 0);
		}
		else 
		{
			send_error_code(0);
		}
	}
	else if( command == COMMAND_PINMODE )
	{
		if( !check_for_parameters(2) ) return;
		//digitalIOSetPinMode(parameters[0], parameters[1]);
	}
}
