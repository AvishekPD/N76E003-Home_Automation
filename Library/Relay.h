#define Relay1      P06_PushPull_Mode
#define Relay2      P07_PushPull_Mode
#define set_Relay1  set_P06
#define clr_Relay1  clr_P06
#define set_Relay2  set_P06
#define clr_Relay2  clr_P07

void Set_Relay(unsigned char i);
void Reset_Relay(unsigned char i);