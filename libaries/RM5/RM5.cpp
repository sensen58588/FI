/*
  读取土壤湿度，读取值范围为 0—1023（空气中）
*/

#include <Arduino.h>
#include <RM5.h>

int pinNumber = 0; //默认模拟数据端口引脚为0
int humidtyThreshold = 50; // 默认土壤湿度阈值为50%

bool setRM5PinNumber(int number)
{
	pinNumber = number;
	return true;
}

bool setHumidtyThreshold (int value) //设置土壤湿度的阈值
{
	bool res = false;
	if (value >=0 && value <= 100)
	{
		humidtyThreshold = value;
		return true;
	}else
		return false;
}

void getGroudHum() 
{
	float data = analogRead(pinNumber);
	// Serial.print("data is");
	// Serial.println(data);
	float humidty = ((1023 - data) / 1023) * 100;
	Serial.println("土壤湿度传感器模块：");
	Serial.print("土壤湿度： ");
	Serial.print(humidty);
	Serial.print("% ");
	if (humidty<humidtyThreshold)
	{
		Serial.println("(土壤过于干燥！)");
	
	}else
		Serial.println("(土壤湿度适宜！)");
}