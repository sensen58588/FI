#ifndef dht11pro_h
#define dht11pro_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define DHT11LIB_VERSION "0.4.1"

#define DHTLIB_OK				0
#define DHTLIB_ERROR_CHECKSUM	-1
#define DHTLIB_ERROR_TIMEOUT	-2

class dht11pro
{
public:
    int read(int pin); //通讯，读值
	int humidity; //湿度整数部分
	int hum_low;	//湿度小数部分
	int temperature;	//温度整数部分
	int temp_low;	//温度小数部分
};
#endif
//
// END OF FILE
//