#include "N76E003.h"
#include "Common.h"
#include "Delay.h"
#include "LCD_2_Wire.h"
#include "Relay.h"
#include "IR_SENSOR.h"

#define scalar          0.08192
// #define scalar          0.12412

void setup(void);
unsigned int ADC_read(void);
void lcd_print_i(unsigned char x_pos, unsigned char y_pos, unsigned int value);
void lcd_print_f(unsigned char x_pos, unsigned char y_pos, unsigned int value);

void main(void)
{
  unsigned int temp = 0;
  unsigned int adc_count = 0;
  unsigned int set_value = 3100;
  unsigned int no_count = 0000;

  Sensor_Init();
  setup();

  while(1)
  {
    adc_count = ADC_read();
    temp = ((unsigned int)(((float)adc_count) / scalar));
    //temp = ((unsigned int)(((float)adc_count)*(vref*100.0))/4096);
    //lcd_print_i(12, 0, adc_count);
    lcd_print_f(11, 1, temp);
    if (temp > set_value)
      Set_Relay(1);
    if (temp < set_value)
      Reset_Relay(1);

    if (Sensor_Read_1()) {
      while(!Sensor_Read_2());
      if(no_count != 99)
        no_count++;
      while(Sensor_Read_2());
    }
    else if (Sensor_Read_2()) {
      while(!Sensor_Read_1);
      if(no_count != 0)
        no_count--;
      while(Sensor_Read_1);
    }

    lcd_print_i(12, 0, no_count);

    if(no_count >= 1)
      Set_Relay(1);
    else if(no_count == 0)
      Reset_Relay(1);

    Timer0_Delay1ms(1);
  }
}


void setup(void)
{

  LCD_init();
  LCD_clear_home();
  LCD_goto(0, 0);
  LCD_putstr("No. Count:");
  LCD_goto(0, 1);
  LCD_putstr("Tmp/deg C:");
  Enable_ADC_AIN1;
}

unsigned int ADC_read(void)
{
  register unsigned int value = 0x0000;
  clr_ADCF;
  set_ADCS;                 
  while(ADCF == 0);
  value = ADCRH;
  value <<= 4;
  value |= ADCRL;
  return value;
}

void lcd_print_i(unsigned char x_pos, unsigned char y_pos, unsigned int value)
{  
  LCD_goto(x_pos, y_pos);
  LCD_putchar((value / 1000) + 0x30);
  LCD_goto((x_pos + 1), y_pos);
  LCD_putchar(((value % 1000) / 100) + 0x30); 
  LCD_goto((x_pos + 2), y_pos);
  LCD_putchar(((value % 100) / 10) + 0x30);
  LCD_goto((x_pos + 3), y_pos);
  LCD_putchar((value % 10) + 0x30);
}

void lcd_print_f(unsigned char x_pos, unsigned char y_pos, unsigned int value)
{ 
  LCD_goto(x_pos, y_pos);
  LCD_putchar((value / 1000) + 0x30);
  LCD_goto((x_pos + 1), y_pos);
  LCD_putchar(((value % 1000) / 100) + 0x30); 
  LCD_goto((x_pos + 2), y_pos);
  LCD_putchar('.');
  LCD_goto((x_pos + 3), y_pos);
  LCD_putchar(((value % 100) / 10) + 0x30);
  LCD_goto((x_pos + 4), y_pos);
  LCD_putchar((value % 10) + 0x30);
}