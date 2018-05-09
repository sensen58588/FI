#ifndef DHT11BEAN_H
#define DHT11BEAN_H

class dht11Bean
{
  public:
  	void setPin(int pin);  //定义数据引脚
    void getHumAndTemp(int type=1); //输出温湿度
    double Fahrenheit(double celsius); //华氏度
    double Kelvin(double celsius); //开氏度
    double dewPoint(double celsius, double humidity); //计算滴露
    double dewPointFast(double celsius, double humidity); //快速计算滴露
  };
#endif