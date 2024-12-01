#include <iostream>
#include <windows.h> 
#include "Keyboard_.h" 

using namespace std;

int x = 1;
int y = 1;
int LastPoint[2] = { 0, 0 };
string Tarray[20][20] = {};

void PaintArray() {
    for (int col = 0; col < 19; col++) {
        for (int row = 0; row < 19; row++) {
            cout << Tarray[col][row];
        }
        cout << endl;
    }
    cout << endl << "x = " << x << ", y = " << y << endl;
}

bool MainLoop() {

    string spaces = " ";
	while (true) {
        system("cls");
	    char key = IsAnyKeyDownDEC();
        switch (key) {
        case 'A': // Move left
            if (x > 0) x -= 1; // Decrease x if it's greater than 0
            break;
        case 'D': // Move right
            if (x < 19) x += 1; // Increase x if it's less than 4
            break;
        case 'W': // Move up
            if (y > 0) y -= 1; // Decrease y if it's greater than 0
            break;
        case 'S': // Move down
            if (y < 19) y += 1; // Increase y if it's less than 4
            break;
        }
        //Tarray[LastPoint[0]][LastPoint[1]] = " ";
        Tarray[y][x] = "*";
        LastPoint[0] = y;
        LastPoint[1] = x;
        PaintArray();
        Sleep(100);
	}

	return true;
}

void FillTheArray() {
    for (int col = 0; col < 20; col++) {
        for (int row = 0; row < 20; row++) {
            Tarray[col][row] = " ";
        }
    }
}

int main() {
    FillTheArray();
	MainLoop();
}