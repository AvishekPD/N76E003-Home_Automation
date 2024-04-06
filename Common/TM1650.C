#include "N76E003.h"

#include "Common.h"
#include "Delay.h"
#include "TM1650.h"
#include "I2C.h"




void TM1650_init(unsigned char brightness_level)
{
	I2C_init();
	TM1650_write(Command_address, brightness_level);
}




void TM1650_write(unsigned char address, unsigned char value)
{
	I2C_start();
	I2C_write(address);
	I2C_write(value);
	I2C_stop();
}


void TM1650_Send_Buff(unsigned char *buff)
{
	int i;
	
	for(i=0;i< 4;i++)
	{
		TM1650_write(Display_address+(i*2),buff[i]);
	}
}



