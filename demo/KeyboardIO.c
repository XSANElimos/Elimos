#include <REGX52.H>
#include "Delay.h"
#include "Typedef.h"

sbit KEY_1 = P2^0;
sbit KEY_2 = P2^1;
sbit KEY_3 = P2^2;
sbit KEY_4 = P2^3;

unsigned char KeyBoard(){

    unsigned char KeyNumber=0;

    if(KEY_1 == 0){Delay(20);while(KEY_1 == 0);Delay(20);KeyNumber = KEY_SUB}
    if(KEY_2 == 0){Delay(20);while(KEY_2 == 0);Delay(20);KeyNumber = KEY_ADD}
    if(KEY_3 == 0){Delay(20);while(KEY_3 == 0);Delay(20);KeyNumber = KEY_SET}
    if(KEY_4 == 0){Delay(20);while(KEY_4 == 0);Delay(20);KeyNumber = KEY_OK}

    return KeyNumber;
}