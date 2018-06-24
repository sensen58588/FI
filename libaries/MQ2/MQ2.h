#include <Arduino.h>
#ifndef MQ2_H
#define MQ2_H

void setD0PinNum(int pinNumber);
void setA0PinNum(int pinNumber);
void initMQ2(int A0, int D0);
double getMQ2Data();

#endif