/*
  农田小气候分析仪程序入口
*/
#include <Wire.h>
#include <math.h>
#include <dht11Bean.h>
#include <GY30.h>

dht11Bean DHT;

/*
  读取土壤湿度，读取值范围为234（水中）—1023（空气中）
*/
const int RM5 = 33;
void getGroudHum() {
  //Serial.println("土壤湿度传感器模块：");
  float data = analogRead(0);
  int key_status = digitalRead(RM5); //1：未达到湿度要求
  if (key_status == 1)
  {
    float humidty = (1 - (data - 223) / 800) * 100;
    Serial.println("土壤过于干燥");
    Serial.print("湿度： ");
    Serial.print(humidty);
    Serial.println("%");
  }
  else
  {
    Serial.println("土壤湿度达标");
    float humidty = (1 - (data - 223) / 800) * 100;
    Serial.print("湿度： ");
    Serial.print(humidty);
    Serial.println("%");
  }
}

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println();
}

void loop()
{
  Serial.println("\n");
  getGroudHum();
  DHT.setPin(23); //设置温湿度传感器的数据传输引脚
  DHT.getHumAndTemp(1);
  getLux();
  delay(2000);
}

