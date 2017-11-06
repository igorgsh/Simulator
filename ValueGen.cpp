#include "ValueGen.h"

#include "math.h"

ValueGen::ValueGen(const ValueGen* c) {
	IntValue = c->IntValue;
	IntMinValue = c->IntMinValue;
	IntMaxValue = c->IntMaxValue;
	RealValue = c->RealValue;
	RealMinValue = c->RealMinValue;
	RealMaxValue = c->RealMaxValue;
	isRandom = c->isRandom;
}

ValueGen::ValueGen() {
	this->IntValue = 0;
	this->IntMinValue = 0;
	this->IntMaxValue = 0;

	this->RealValue = 0.0;
	this->RealMinValue = 0.0;
	this->RealMaxValue = 0.0;

	isRandom = false;
}

ValueGen::ValueGen(int value, int minValue, int maxValue) {
	this->IntValue = value;
	isRandom = false;
	if (maxValue > minValue) {
		this->IntMinValue = minValue;
		this->IntMaxValue = maxValue;
		isRandom = true;
	}

}

ValueGen::ValueGen(double value, double minValue, double maxValue) {
	this->RealValue = value;
	isRandom = false;
	if (maxValue > minValue) {
		this->RealMinValue = minValue;
		this->RealMaxValue = maxValue;
		isRandom = true;
	}
}

int ValueGen::GetIntValue() {
	if (isRandom) {
		return random(IntMinValue, IntMaxValue);
	}
	else {
		return IntValue;
	}
}
double ValueGen::GetRealValue() {
	if (isRandom) {
		return (double)random(RealMinValue * factor, RealMaxValue* factor) / (double)factor;
	}
	else {
		return RealValue;
	}
}

void ValueGen::Set(int value, int minValue, int maxValue) {
	IntValue = value;
	IntMinValue = minValue;
	IntMaxValue = maxValue;
	isRandom = (maxValue > minValue);

	RealValue = (double)value;
	RealMinValue = (double)minValue;
	RealMaxValue = (double)maxValue;
}

void ValueGen::Set(double value, double minValue, double maxValue) {
	RealValue = value;
	RealMinValue = minValue;
	RealMaxValue = maxValue;
	isRandom = (maxValue > minValue);

	IntValue = (int)value;
	IntMinValue = (int)minValue;
	IntMaxValue = (int)maxValue;

}
