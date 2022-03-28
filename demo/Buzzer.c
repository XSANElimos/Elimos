#include <REGX52.H>
#include "Delay.h"

sbit Buzzer=P3^5;

/**
  * @brief 蜂鸣器发声，对应P3.5/T1
  * @param 频率
  * @retval 无
  */
void Buzzer_beeptime(unsigned int ms){
    for (unsigned int i = 0; i < ms; i++)
    {
        Buzzer=!Buzzer;
        Delay(1);
    }
    
}

void Buzzer_notice(){
    for (unsigned int i = 0; i < 500; i++)
    {
        Buzzer=!Buzzer;
        Delay(1);
    }
}

void Buzzer_alert(){
    for (unsigned int i = 0; i < 100; i++)
    {
        Buzzer=!Buzzer;
        Delay(1);
    }
}