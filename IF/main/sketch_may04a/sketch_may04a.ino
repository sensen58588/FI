/*
  农田小气候分析仪程序入口
*/

#include <dht11.h>
dht11 DHT11;

const int DHT11PIN = 22; //DHT11的数据读取引脚为22

void setup() {

  Serial.begin(9600);
  //pinMode(led1,INPUT);
}

void loop() {
  Serial.println("\n");
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Read Sensor: ");
  switch (chk)
  {
    case 0:
      Serial.println("OK");
      break;
    case -1:
      Serial.println("CHECKSUM ERROR");
      break;
    case -2:
      Serial.println("TIME OUT ERROR");
      break;
    default:
      Serial.println("UNKNOWN ERROR");
      break;
  }
  Serial.print("chk is: ");
  Serial.println(chk);
  Serial.print("湿度(%): ");
  Serial.println((float)DHT11.humidity, 2);
  Serial.print("温度(oC)：");
  Serial.println((float)DHT11.temperature, 2);
  delay(3000);

}
