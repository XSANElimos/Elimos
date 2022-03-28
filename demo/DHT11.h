#ifndef __DHT11_H
#define __DHT11_H

#include <reg52.h>

void DHT11_delay_us(unsigned char n);
void DHT11_delay_ms(unsigned int z);
void DHT11_start();
unsigned char DHT11_rec_byte();
void DHT11_receive();

#endif