/*
  农田小气候分析仪程序入口
*/
#include <Wire.h> 
#include <math.h>
#include <dht11Bean.h> //导入DHT11空气温湿度传感器
#include <GY30.h> //导入GY30光敏数据传感器
#include <RM5.h>  //导入RM5土壤湿度传感器
#include <MQ2.h> //导入MQ2气体传感器

dht11Bean DHT;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println();
  setHumidtyThreshold(40); //设置土壤湿度阈值（百分比）
  setRM5PinNumber(0); //设置土壤湿度传感器模拟数据端口引脚为0
  initMQ2(3,52); //初始化MQ2传感器的A0,D0引脚
}

void loop()
{
  Serial.println("\n");
  getGroudHum();//输出土壤湿度数据
  Serial.println();
  DHT.setPin(23); //设置温湿度传感器的数据传输引脚
  DHT.getHumAndTemp(1); //默认输出不含额外信息
  Serial.println();
  getLux(); //输出光照强度
  Serial.println();
  getMQ2Data(); //输出甲烷，天然气气体检测数据
 
  delay(2000);
}

