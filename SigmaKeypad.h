#pragma once
#include "d:\Documents\Arduino\libraries\Keypad\src\Keypad.h"
class SigmaKeypad :
	public Keypad
{
public:
	SigmaKeypad(char *userKeymap, byte *row, byte *col, byte numRows, byte numCols);
	SigmaKeypad(byte *row, byte *col);
	int getKeyN();
private:
	char* _Keymap;
	byte _row;
	byte _col;
	const static byte ROWS = 4;
	const static byte COLS = 4;
	char keys[ROWS][COLS] = {
		{ '1','2','3','A' },
		{ '4','5','6','B' },
		{ '7','8','9','C' },
		{ '*','0','#','D' }
	};
	byte* rowPins[ROWS];
	byte* colPins[COLS];

};

