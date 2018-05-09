#include <dht11Bean.h>
#include <dht11pro.h>

dht11pro DHTPRO;
int DHT11PIN = 22;//DHT11的数据读取引脚默认为22

//------------------------START-----------------------------
void dht11Bean::setPin(int pin)
{
  DHT11PIN = pin;
}

//摄氏温度度转化为华氏温度
double dht11Bean::Fahrenheit(double celsius)
{
  return 1.8 * celsius + 32;
  }

//摄氏温度转化为开氏温度  
double dht11Bean::Kelvin(double celsius)
{
  return celsius + 273.15;
  }

// 露点（点在此温度时，空气饱和并产生露珠）
// 参考: http://wahiduddin.net/calc/density_algorithms.htm
double dht11Bean::dewPoint(double celsius, double humidity)
{
  double A0 = 373.15 / (273.15 + celsius);
  double SUM = -7.90298 * (A0 - 1);
  SUM += 5.02808 * log10(A0);
  SUM += -1.3816e-7 * (pow(10, (11.344 * (1 - 1 / A0))) - 1) ;
  SUM += 8.1328e-3 * (pow(10, (-3.49149 * (A0 - 1))) - 1) ;
  SUM += log10(1013.246);
  double VP = pow(10, SUM - 3) * humidity;
  double T = log(VP / 0.61078); // temp var
  return (241.88 * T) / (17.558 - T);
}

// 快速计算露点，速度是5倍dewPoint()
// 参考: http://en.wikipedia.org/wiki/Dew_point
double dht11Bean::dewPointFast(double celsius, double humidity)
{
  double a = 17.271;
  double b = 237.7;
  double temp = (a * celsius) / (b + celsius) + log(humidity / 100);
  double Td = (b * temp) / (a - temp);
  return Td;
}

/*获取温湿度数据
  type值默认1，输出温湿度；
  type=0，输出额外内容
*/
void dht11Bean::getHumAndTemp(int type = 1)
{
  //Serial.println("\n");
  int chk = DHTPRO.read(DHT11PIN); //获取当前的温湿度传感器状态
  Serial.print("空气温湿度传感器: ");
  switch (chk)
  {
    case DHTLIB_OK:
      Serial.println("OK");
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.println("OK");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.println("Time out error");
      break;
    default:
      Serial.println("Unknown error");
      break;
  }
  Serial.print("空气湿度 (%): ");
  Serial.println((float)(DHTPRO.humidity + DHTPRO.hum_low * 0.01), 2);

  Serial.print("空气温度 (摄氏度): ");
  Serial.println((float)(DHTPRO.temperature + DHTPRO.temp_low * 0.01), 2);
  if (type == 0)
  {
    Serial.print("华氏温度(oF): ");
    Serial.println(Fahrenheit(DHTPRO.temperature), 2);

    Serial.print("开氏温度 (K): ");
    Serial.println(Kelvin(DHTPRO.temperature), 2);

    Serial.print("露点 (oC): ");
    Serial.println(dewPoint(DHTPRO.temperature, DHTPRO.humidity));

    Serial.print("快速计算露点 (oC): ");
    Serial.println(dewPointFast(DHTPRO.temperature, DHTPRO.humidity));
  }
}

//--------------------END----------------------