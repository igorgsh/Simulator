/*
 Name:		Simulator.cpp
 Created:	27.10.17 14:43:30
 Author:	Igor Shevchenko
 Editor:	http://www.visualmicro.com
*/

#include "Simulator.h"

Simulator::Simulator(int numberOfValueGens, int numberOfPins, byte* keypadRowPins, byte* keypadColPins) {
	init(numberOfValueGens, numberOfPins, new SigmaKeypad(keypadRowPins, keypadColPins));
}


Simulator::Simulator(int numberOfValueGens, int numberOfPins, SigmaKeypad* keypad) {

	init(numberOfValueGens, numberOfPins, keypad);
}

void Simulator::init(int numberOfValueGens, int numberOfPins, SigmaKeypad* keypad) {
	this->numberOfValueGens = numberOfValueGens;
	this->numberOfPins = numberOfPins;
	this->keypad = keypad;
	ValueGens = new ValueGen*[numberOfValueGens];
	for (int i = 0; i < numberOfValueGens; i++) {
		ValueGens[i] = new ValueGen[numberOfPins];
	}
}

int Simulator::GetIntResult(int pin) {
	return ValueGens[ValueGenNumber][pin].GetIntValue();
}

double Simulator::GetRealResult(int pin) {
	return ValueGens[ValueGenNumber][pin].GetRealValue();
}
/*
bool Simulator::SetValueGen(int ValueGenNumber, const ValueGen* ValueGen0) {
ValueGens[ValueGenNumber] = new ValueGen(ValueGen0);
}
*/
bool Simulator::SetValueGen(int ValueGenNumber, int pin, int value, int minValue, int maxValue) {
	if (ValueGenNumber >= 0 && ValueGenNumber < numberOfValueGens && pin >= 0 && pin < numberOfPins) {
		ValueGens[ValueGenNumber][pin].Set(value, minValue, maxValue);
		return true;
	}
	return false;
}

bool Simulator::SetValueGen(int ValueGenNumber, int pin, double value, double minValue, double maxValue) {
	//Serial.println("if1=" + String(ValueGenNumber >= 0 && ValueGenNumber < numberOfValueGens));
	//Serial.println("if2=" + String(pin >= 0 && pin < numberOfPins));
	if (ValueGenNumber >= 0 && ValueGenNumber < numberOfValueGens && pin >= 0 && pin < numberOfPins) {
		ValueGens[ValueGenNumber][pin].Set(value, minValue, maxValue);
		return true;
	}
	return false;
}


bool Simulator::loop() {
	if (keypad != NULL) {
		int k = keypad->getKeyN();
		if (k >= 0 && k < numberOfValueGens) {
			ValueGenNumber = k;
			return true;
		}
	}
	return false;
}
