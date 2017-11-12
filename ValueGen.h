#pragma once
#include "Arduino.h"

class ValueGen
{
public:
	ValueGen(int value, int minValue=0, int maxValue=0);
	ValueGen(double value, double minValue=0, double maxValue=0);
	ValueGen();
	ValueGen(const ValueGen* c);
	void Set(int value, int minValue = 0, int maxValue = 0);
	void Set(double value, double minValue = 0, double maxValue = 0);
	int GetIntValue();
	double GetRealValue();
	void Copy(ValueGen* newValue);
private:
	int IntValue;
	double RealValue;
	bool isRandom = false;
	int IntMinValue;
	int IntMaxValue;
	double RealMinValue;
	double RealMaxValue;
	const long factor = 1000;
};

