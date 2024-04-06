#include "N76E003.h"
#include "Common.h"
#include "Relay.h"

void Set_Relay(unsigned char i)
{
    switch(i){
        case 1:
            set_Relay1;
            break;

        case 2:
            set_Relay2;
            break;
    }
}

void Reset_Relay(unsigned char i)
{
    switch(i){
        case 1:
            set_Relay1;
            break;

        case 2:
            set_Relay2;
            break;
    }
}