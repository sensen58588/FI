/*
  农田小气候分析仪程序入口
*/
#include <Wire.h> 
#include <math.h>
#include <dht11Bean.h> //导入DHT11空气温湿度传感器
#include <GY30.h> //导入GY30光敏数据传感器
#include <RM5.h>  //导入RM5土壤湿度传感器
#include <MQ2.h> //导入MQ2气体传感器
#include <LiquidCrystal.h>
dht11Bean DHT;
const int rs = 41, en = 39, d4 = 49, d5 = 47, d6 = 45, d7 = 43;
auto lcd = LiquidCrystal(rs, en, d4, d5, d6, d7);

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("气候分析仪已启动...");
  setHumidtyThreshold(40); //设置土壤湿度阈值（百分比）
  setRM5PinNumber(0); //设置土壤湿度传感器模拟数据端口引脚为0
  initMQ2(3,52); //初始化MQ2传感器的A0,D0引脚
  DHT.setPin(23); //设置温湿度传感器的数据传输引脚
  lcd.begin(16, 2);
  lcd.print("Analyzer start.....");
  lcd.setCursor(1,1);
  lcd.print("han xiao qiang");
  delay(3000);
}

void loop()
{ 
  Serial.println("\n");
  double groudHum = getGroudHum();//输出土壤湿度数据
  String data = (String)groudHum+" %";
  displayInfo("groud humity:",data);
  Serial.println();
 
  DHT.showHumAndTemp(1); //默认输出不含额外信息
  double humity = DHT.getHumity();
  double temp = DHT.getTemp();
  data = (String)humity+" %";
  displayInfo("air humity:",data);
  data = (String)temp + " C";
  displayInfo("air temperature:",data);
  
  Serial.println();
  double lux = getLux()*1.00; //输出光照强度
  Serial.println();
  data = (String)lux +" Lx";
  displayInfo("Light Intensity:",data);
  
  double CO2 = getMQ2Data(); //输出甲烷，天然气气体检测数据
  data = (String)CO2+" %";
  displayInfo("CO2 value:",data);
}
void displayInfo(String info,String data)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(info);
  lcd.setCursor(0,1);
  lcd.print(data);
  delay(3000);
  lcd.clear();
}

