/*
 Name:		Simulator.cpp
 Created:	27.10.17 14:43:30
 Author:	Igor Shevchenko
 Editor:	http://www.visualmicro.com
*/

#include "Simulator.h"

Simulator::Simulator(int numberOfValueGens, int numberOfPins, const byte* pinMap) {
	init(numberOfValueGens, numberOfPins, pinMap, NULL);
}

Simulator::Simulator(int numberOfValueGens, int numberOfPins, const byte* pinMap, SigmaKeypad* keypad) {
	init(numberOfValueGens, numberOfPins, pinMap, keypad);
}
Simulator::Simulator(int numberOfValueGens, int numberOfPins, const byte* pinMap, byte* keypadRowPins, byte* keypadColPins) {
	init(numberOfValueGens, numberOfPins, pinMap, new SigmaKeypad(keypadRowPins, keypadColPins));
}



int Simulator::findPin(int pin) {
	for (int i = 0; i < numberOfPins; i++) {
		if (pinMap[i] == pin)
			return i;
	}
	return -1;
}


void Simulator::init(int numberOfValueGens, int numberOfPins,const byte* pinMap, SigmaKeypad* keypad) {
	this->numberOfCase = numberOfValueGens;
	this->numberOfPins = numberOfPins;
	this->keypad = keypad;
	this->pinMap = pinMap;
	CaseValues = new ValueGen*[numberOfValueGens];
	for (int i = 0; i < numberOfValueGens; i++) {
		CaseValues[i] = new ValueGen[numberOfPins];
	}
}

int Simulator::GetIntResult(int pin) {
	int p = findPin(pin);
	if (p != -1) {
		return CaseValues[CaseNumber][p].GetIntValue();
	}
	return -9999;
}

double Simulator::GetRealResult(int pin) {
	int p = findPin(pin);
	if (p != -1) {
		return CaseValues[CaseNumber][p].GetRealValue();
	}
	return -999.9999;
}
bool Simulator::SetPinValue(int ValueGenNumber, int pin, int value, int minValue, int maxValue) {
	int p = findPin(pin);
	if (ValueGenNumber >= 0 && ValueGenNumber < numberOfCase && p >= 0 && p < numberOfPins) {
		CaseValues[ValueGenNumber][p].Set(value, minValue, maxValue);
		CaseValues[ValueGenNumber][p].Set((double)value, (double)minValue, (double)maxValue);
		return true;
	}
	return false;
}

bool Simulator::SetPinValue(int ValueGenNumber, int pin, double value, double minValue, double maxValue) {
	int p = findPin(pin);
	if (ValueGenNumber >= 0 && ValueGenNumber < numberOfCase && p >= 0 && p < numberOfPins) {
		CaseValues[ValueGenNumber][p].Set(value, minValue, maxValue);
		CaseValues[ValueGenNumber][p].Set((int)value, (int)minValue, (int)maxValue);
		return true;
	}
	return false;
}

bool Simulator::SetCaseValues(int newCaseNumber, int originalCaseNumber) {
	bool res = false;

	if (newCaseNumber>=0 && newCaseNumber<numberOfCase 
		&& originalCaseNumber >= 0 && originalCaseNumber < numberOfCase) {
		for (int i = 0; i < numberOfPins; i++) {
			CaseValues[originalCaseNumber][i].Copy(&(CaseValues[newCaseNumber][i]));
		}
	}

	return res;
}


bool Simulator::loop() {
	if (keypad != NULL) {
		int k = keypad->getKeyN();
		if (k >= 0 && k < numberOfCase) {
			CaseNumber = k;
			return true;
		}
	}
	return false;
}
