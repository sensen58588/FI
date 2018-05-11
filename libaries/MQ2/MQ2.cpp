#include <MQ2.h>

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

void getMQ2Data()
{
	int sensorValue = analogRead(MQ2A0);
	Serial.println("MQ2气体传感器：");
	Serial.print("甲烷，天然气检测数据()：");
	Serial.println(sensorValue);
	int keyDigital = digitalRead(MQ2D0); //可以手动调节灵敏度
	if (keyDigital!=0)
	{
		Serial.println("安全");
	}else
	{
	  Serial.println("危险气体泄漏！！！！！！！");
	}
}