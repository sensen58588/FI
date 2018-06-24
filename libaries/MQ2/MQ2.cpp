#include <MQ2.h>
#include <Arduino.h>

int MQ2D0 = 52; //MQ2传感器D0数字数据输出引脚
int MQ2A0 = 3; //MQ2传感器A0模拟数据输出引脚

void setD0PinNum(int pinNumber)
{
	MQ2D0 = pinNumber;
}
void setA0PinNum(int pinNumber)
{
	MQ2A0 = pinNumber;
}

void initMQ2(int A0, int D0)
{	
	setD0PinNum(D0);
	setA0PinNum(A0);
	pinMode(A0,INPUT);
}

double getMQ2Data()
{
	int sensorValue = analogRead(MQ2A0); //获取气敏传感器的检测数值
	Serial.println("MQ2气体传感器：");
	Serial.print("甲烷，天然气检测数据()：");
	Serial.println(sensorValue);	//输出检测到的气体浓度值（0-1023）
	int keyDigital = digitalRead(MQ2D0); //读取A0引脚的电平值
	if (keyDigital==0) //低电平表示超过设定的阈值
	{
		Serial.println("危险气体泄漏！！");
	}else
	{
		Serial.println("安全");	 
	}
	return sensorValue*1.0/1023;
}