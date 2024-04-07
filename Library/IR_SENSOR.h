#define IR_SENSOR1_EN() P13_Input_Mode
#define IR_SENSOR2_EN() P14_Input_Mode

#define IR_SENSOR1()    P13
#define IR_SENSOR2()    P14


void Sensor_Init(void);
unsigned char Sensor_Read_1(void);
unsigned char Sensor_Read_2(void);