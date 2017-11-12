/*
 Name:		Simulator.h
 Created:	27.10.17 14:43:30
 Author:	Igor Shevchenko
 Editor:	http://www.visualmicro.com
*/

#ifndef _Simulator_h
#define _Simulator_h
#include "Arduino.h"
/*
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
*/
#include "SigmaKeypad.h"
#include "ValueGen.h"

class Simulator
{
public:
	Simulator(int numberOfValueGens, int numberOfPins, const byte* pinMap);
	Simulator(int numberOfValueGens, int numberOfPins, const byte* pinMap, SigmaKeypad* keypad);
	Simulator(int numberOfValueGens, int numberOfPins, const byte* pinMap, byte* keypadRowPins, byte* keypadColPins);

//	Simulator(int numberOfValueGens, int numberOfPins, byte* keypadRowPins, byte* keypadColPins);
//	Simulator(int numberOfValueGens, int numberOfPins, SigmaKeypad* keypad=NULL);
	int GetCaseNumber() { return CaseNumber; };
	void SetCaseNumber(int value) { if (value >= 0 && value < numberOfCase) { CaseNumber = value; }; };
	int GetIntResult(int pin);
	double GetRealResult(int pin);
	//	bool SetValueGen(int ValueGenNumber, const ValueGen* ValueGen0);
	bool SetPinValue(int ValueGenNumber, int pin, int value, int minValue = 0, int maxValue = 0);
	bool SetPinValue(int ValueGenNumber, int pin, double value, double minValue = 0, double maxValue = 0);
	bool SetCaseValues(int newCaseNumber, int originalNumber);
	bool loop();

private:
	int CaseNumber = -1;
	int numberOfCase = 0;
	int numberOfPins = 0;
	SigmaKeypad* keypad;
	ValueGen** CaseValues;
	const byte* pinMap;
	void init(int numberOfCase, int numberOfPins,const byte* pinMap, SigmaKeypad* keypad);
	int findPin(int pin);

};



#endif

