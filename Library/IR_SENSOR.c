#include "IR_SENSOR.h"

void Sensor_Init(void)
{
    IR_SENSOR1_EN();
    IR_SENSOR2_EN();
}

unsigned char Sensor_Read_1(void)
{
    return IR_SENSOR1();
}

unsigned char Sensor_Read_2(void)
{
    return IR_SENSOR2();
}
