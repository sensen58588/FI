#include <Arduino.h>
#ifndef RM5_H
#define RM5_H

double getGroudHum(); //输出土壤湿度
bool setHumidtyThreshold (int value); //设置土壤湿度的阈值
bool setRM5PinNumber(int number);

#endif