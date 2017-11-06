#include "SigmaKeypad.h"


SigmaKeypad::SigmaKeypad(byte *row, byte *col)
	: Keypad(makeKeymap(keys), row, col, ROWS, COLS)
{
	_Keymap = makeKeymap(keys);
	_row = ROWS;
	_col = COLS;
}


SigmaKeypad::SigmaKeypad(char *userKeymap, byte *row, byte *col, byte numRows, byte numCols) 
	: Keypad(userKeymap, row, col, numRows, numCols)
{
	_Keymap = userKeymap;
	_row = numRows;
	_col = numCols;
}

int SigmaKeypad::getKeyN() {
	char key = getKey();

	if (key) {
		for (int r = 0; r < _row; r++) {
			for (int c = 0; c < _col; c++) {
				int i = r* _row + c;
				if (key == _Keymap[i]) {
					return i;
				}
			}
		}
	}
	return -1;
}