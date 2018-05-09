#include <GY30.h>
#include <Wire.h>
#include <Arduino.h>

int BH1750address = 0x23;//芯片地址为16位23

byte buff[2];

void getLux()
{
  int i;

  uint16_t val=0;

  BH1750_Init(BH1750address);

  //delay(1000);

  if(2==BH1750_Read(BH1750address))

  {

   val=((buff[0]<<8)|buff[1])/1.2;

   Serial.print("光照强度（Lux）：");

   Serial.print(val,DEC);     

  }

}



int BH1750_Read(int address) //

{

  int i=0;

  Wire.beginTransmission(address);

  Wire.requestFrom(address, 2);

  while(Wire.available()) 

  {

    buff[i] = Wire.read(); 

    i++;

  }

  Wire.endTransmission();  

  return i;

}


void BH1750_Init(int address) 

{

  Wire.beginTransmission(address);
  Wire.write(0x10);
  Wire.endTransmission();

}