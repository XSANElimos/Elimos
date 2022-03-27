
#include <reg52.h>
#include "../Driver_h/delay.h"
#include "../Driver_h/ds1302.h"

sbit ds1302_sclk = P2^1;
sbit ds1302_sda = P2^0;				//ע�⣺ʹ��ʱ��������ñ�̽�J15
sbit ds1302_rst = P2^4;				//��λ�������ݴ����ڼ������ߵ�ƽ

//������ʱ�����������룬�½������
//����ָ��
/*
	bit7 	bit6			bit5  	bit4		bit3		bit2		bit1  	bit0
	1			ram/#ck		a4			a3			a2			a1			a0			rd/#w

bit6:ram/#ck		��Ϊ1�����ڲ���RAM������31���ֽ�
								��Ϊ0�����ڲ���ʱ������
*/

void ds1302_init()
{
	ds1302_rst = 0;
	ds1302_sclk = 0;
	ds1302_cancelProtect();		//ȡ��д����
	ds1302_start();						//����ʱ
}

unsigned char ds1302_readClk(unsigned char addr)
{
	unsigned char temp = 0,i = 0;
	
	ds1302_rst = 0;
	ds1302_sclk = 0;
	Delay5us();								//����4us����
	ds1302_rst = 1;						//�ɵ͵��ߣ�ʹ�ܶ�д
	
	temp = addr<<1 | 0x81;		//RD=1,bit7=1
	for(i=0;i<8;i++)					//��д��λ�����͵�ַ
	{
		ds1302_sclk = 0;
		if(temp & 0x01)
			ds1302_sda = 1;
		else
			ds1302_sda = 0;
		ds1302_sclk = 1;				//�ṩ�����أ������ݷ��ͳ�ȥ

		temp>>=1;								//׼��������һλ
	}
	
	//��ȡ����
	temp = 0;									//���㣬׼�����ն�����������ǰSDA = 1
	ds1302_sda = 1;
	
	for(i=0;i<8;i++)
	{
		temp >>=1;								//�ճ����λ��׼�����գ�Ҳ��ֱ�ӷ��õ���Ӧλ��
		ds1302_sclk = 0;				//�����½��أ���ȡ����
		if(ds1302_sda == 1)
			temp |= 0x80;
		ds1302_sclk = 1;				//����ʱ��
	}
	ds1302_sclk = 0;	
//	Delay5us();								//����4us����
	ds1302_rst = 0;			
	
	return temp;
}	

//дʱ��
unsigned char ds1302_writeClk(unsigned char addr,unsigned char dat)
{
	unsigned char temp = 0,i = 0;
	
	ds1302_rst = 0;
	ds1302_sclk = 0;
	Delay5us();					//����4us����
	ds1302_rst = 1;			//�ɵ͵��ߣ�ʹ�ܶ�д
	
	temp = addr<<1 | 0x81;		//RD=1,bit7=1
	for(i=0;i<8;i++)					//��д��λ�����͵�ַ
	{
		ds1302_sclk = 0;
		if(temp & 0x01)
			ds1302_sda = 1;
		else
			ds1302_sda = 0;
		ds1302_sclk = 1;				//�ṩ�����أ������ݷ��ͳ�ȥ

		temp>>=1;								//׼��������һλ
	}
	
	temp = dat;								//׼��Ҫ���͵�����
	for(i=0;i<8;i++)
	{
		ds1302_sclk = 0;
		if(temp & 0x01)
			ds1302_sda = 1;
		else
			ds1302_sda = 0;
		ds1302_sclk = 1;				//�ṩ�����أ������ݷ��ͳ�ȥ

		temp>>=1;								//׼��������һλ
	}
	ds1302_sclk = 0;	
//	Delay5us();							//����4us����
	ds1302_rst = 0;			
	
	return temp;
}

//��RAM
unsigned char ds1302_readRam(unsigned char addr)
{
	unsigned char temp = 0,i = 0;
	
	ds1302_rst = 0;
	ds1302_sclk = 0;
	Delay5us();					//����4us����
	ds1302_rst = 1;			//�ɵ͵��ߣ�ʹ�ܶ�д
	
	temp = addr<<1 | 0xc1;		//RD=1,bit7=1,bit6=1
	for(i=0;i<8;i++)					//��д��λ�����͵�ַ
	{
		ds1302_sclk = 0;
		if(temp & 0x01)
			ds1302_sda = 1;
		else
			ds1302_sda = 0;
		ds1302_sclk = 1;				//�ṩ�����أ������ݷ��ͳ�ȥ

		temp>>=1;								//׼��������һλ
	}
	
	//��ȡ����
	temp = 0;									//���㣬׼�����ն�����������ǰSDA = 1
	ds1302_sda = 1;
	
	for(i=0;i<8;i++)
	{
		temp >>=1;								//�ճ����λ��׼�����գ�Ҳ��ֱ�ӷ��õ���Ӧλ��
		ds1302_sclk = 0;					//�����½��أ���ȡ����
		if(ds1302_sda == 1)
			temp |= 0x80;
		ds1302_sclk = 1;				//����ʱ��
	}
	ds1302_sclk = 0;	
//	Delay5us();								//����4us����
	ds1302_rst = 0;			
	
	return temp;
}	

//дRAM
unsigned char ds1302_writeRam(unsigned char addr,unsigned char dat)
{
	unsigned char temp = 0,i = 0;
	
	ds1302_rst = 0;
	ds1302_sclk = 0;
	Delay5us();					//����4us����
	ds1302_rst = 1;			//�ɵ͵��ߣ�ʹ�ܶ�д
	
	temp = addr<<1 | 0xc1;		//RD=1,bit7=1
	for(i=0;i<8;i++)					//��д��λ�����͵�ַ
	{
		ds1302_sclk = 0;
		if(temp & 0x01)
			ds1302_sda = 1;
		else
			ds1302_sda = 0;
		ds1302_sclk = 1;				//�ṩ�����أ������ݷ��ͳ�ȥ

		temp>>=1;								//׼��������һλ
	}
	
	temp = dat;								//׼��Ҫ���͵�����
	for(i=0;i<8;i++)
	{
		ds1302_sclk = 0;
		if(temp & 0x01)
			ds1302_sda = 1;
		else
			ds1302_sda = 0;
		ds1302_sclk = 1;				//�ṩ�����أ������ݷ��ͳ�ȥ

		temp>>=1;								//׼��������һλ
	}
	ds1302_sclk = 0;	
//	Delay5us();							//����4us����
	ds1302_rst = 0;			
	
	return temp;
}

//ʱ�ӼĴ��������ݴ洢��ʽΪBCD��
unsigned char  bcd2dec(unsigned char bcd)
{
	unsigned char dec = 0;
	
	dec = (bcd>>4)*10 + (bcd & 0x0f);
	
	return dec;
}

unsigned char  dec2bcd(unsigned char dec)
{
	unsigned char bcd = 0;
	
	bcd = ((dec/10)<<4 ) | (dec%10);

	return bcd;
}


//��Ķ���д
unsigned char ds1302_readSec()
{
	unsigned char temp = 0;
	
	temp = ds1302_readClk(ADDR_SEC);
	temp &= 0x7f;						//���λ��ֹͣλ�����ε�
	
	temp = bcd2dec(temp);		//ת��10����
	return temp;						
}

//д��
void ds1302_writeSec(unsigned char sec)
{
	sec %= 60;			//����ȡֵ��0~59
	sec = dec2bcd(sec);	//תbcd
	ds1302_writeClk(ADDR_SEC,sec);
}

//ֹͣDS1302
void ds1302_stop(void)
{
	unsigned char temp = 0;
	
	temp = ds1302_readClk(ADDR_SEC);
	temp |= 0x80;
	ds1302_writeClk(ADDR_SEC,temp);
}

//��ds1302
void ds1302_start(void)
{
	unsigned char temp = 0;
	
	temp = ds1302_readClk(ADDR_SEC);
	temp &= 0x7f;
	ds1302_writeClk(ADDR_SEC,temp);
}

//����
unsigned char ds1302_readMin()
{
	unsigned char temp = 0;
	
	temp = ds1302_readClk(ADDR_MIN);
	temp = bcd2dec(temp);		//ת��10����
	return temp;						
}

//д��
void ds1302_writeMin(unsigned char min)
{
	min %= 60;			//����ȡֵ��0~59
	min = dec2bcd(min);	//תbcd
	ds1302_writeClk(ADDR_MIN,min);
}

//�������24Сʱ��
//��ʱ
//����
unsigned char ds1302_readHour()
{
	unsigned char temp = 0;
	
	temp = ds1302_readClk(ADDR_HR);
	temp &= 0x3f;											//ֻҪ��6λ
	temp = bcd2dec(temp);							//ת��10����
	return temp;						
}

//дʱ
void ds1302_writeHour(unsigned char hour)
{
	hour %= 24;			//����ȡֵ��0~23
	hour = dec2bcd(hour);	//תbcd
	ds1302_writeClk(ADDR_HR,hour);
}


//������
unsigned char ds1302_readDate()
{
	unsigned char temp = 0;
	
	temp = ds1302_readClk(ADDR_DATE);
	temp &= 0x3f;											//ֻҪ��6λ
	temp = bcd2dec(temp);							//ת��10����
	return temp;						
}


//д����
unsigned char ds1302_writeDate(unsigned char date)
{
	unsigned char temp = 0;
	
	temp = ds1302_readClk(ADDR_MONTH);			//�ȶ��·ݣ������·����Ʋ���ȡֵ��Χ
	temp = bcd2dec(temp);
	switch(temp)
	{
		case 1:		//1~31��
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(date > 31 || date < 1)
				temp = 0xff;
			break;
		case 2:
				temp = ds1302_readClk(ADDR_YEAR);
				temp = bcd2dec(temp);
				if((temp%4==0  && temp%100 != 0) || temp%400 == 0)		//����
				{
					if(date<1 || date>29)		//���꣬���ܳ�29
						temp = 0xff;
				}
				else
				{
					if(date<1 || date>28)
						temp = 0xff;
				}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(date>30 || date<1)
				temp = 0xff;
			break;
	}
	
	if(temp != 0xff)
	{
		date = dec2bcd(date);
		ds1302_writeClk(ADDR_DATE,date);
		temp = 0;																//�ɹ�д��
	}
	
	return temp;						
}

//���·�
unsigned char ds1302_readMonth()
{
	unsigned char temp = 0;
	
	temp = ds1302_readClk(ADDR_MONTH);
	temp &= 0x1f;
	temp = bcd2dec(temp);
	
	return temp;
}

//д�·�
unsigned char ds1302_writeMonth(unsigned char month)
{
	unsigned char temp = 0;
	
	if(month<1 || month>12)
		temp = 0xff;
	else
	{
		month = dec2bcd(month);
		ds1302_writeClk(ADDR_MONTH,month);
	}
		
	return temp;
}


//������
unsigned char ds1302_readDay()
{
	unsigned char temp = 0;
	
	temp = ds1302_readClk(ADDR_DAY);
	temp &= 0x07;
	temp = bcd2dec(temp);
	
	return temp;
}

//д����
unsigned char ds1302_writeDay(unsigned char day)
{
	unsigned char temp = 0;
	
	if(day<1 || day>7)
		temp = 0xff;
	else
	{
		day = dec2bcd(day);
		ds1302_writeClk(ADDR_DAY,day);
	}
		
	return temp;
}

//����
unsigned char ds1302_readYear()
{
	unsigned char temp = 0;
	
	temp = ds1302_readClk(ADDR_YEAR);
	temp = bcd2dec(temp);
	
	return temp;
}

//д��
unsigned char ds1302_writeYear(unsigned char year)
{
	unsigned char temp = 0;
	
	if(year>99)
		temp = 0xff;
	else
	{
		year = dec2bcd(year);
		ds1302_writeClk(ADDR_YEAR,year);
	}
		
	return temp;
}

//д����
void ds1302_writeProtect()
{	
	ds1302_writeClk(ADDR_CTRL,0x80);	//���λд1
}

//ȡ��д����
void ds1302_cancelProtect()
{						
	ds1302_writeClk(ADDR_CTRL,0);
}



