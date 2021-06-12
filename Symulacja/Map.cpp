#include <iostream>
#include <windows.h>
#include <time.h>
#include "Map.h"

using namespace std;

Map::Map(int w, int h) {
	width = w;
	height = h;

	board = new int* [width];
	for (int k = 0; k < width; k++) {
		board[k] = new int[height];
	}

	for (int u = 0; u < width; u++) {
		for (int v = 0; v < height; v++) {
			board[u][v] = 0;
		}
	}

	AdditivesMap = new int* [width];
	for (int q = 0; q < width; q++) {
		AdditivesMap[q] = new int[height];
	}

	for (int r = 0; r < width; r++) {
		for (int s = 0; s < height; s++) {
			AdditivesMap[r][s] = 0;
		}
	}
}

Map::~Map() {
	for (int i(0); i < height; ++i) {
		delete[] board[i];
	}
	delete[] board;

	for (int i(0); i < height; ++i) {
		delete[] AdditivesMap[i];
	}
	delete[] AdditivesMap;
}

int Map::getWidth()
{
	return width;
}

int Map::getHeight()
{
	return height;
}

int** Map::getArrayAdditivesMap() {
	return AdditivesMap;
}

int** Map::getBoard() {
	return board;
}

void Map::setArrayAdditivesMap(unsigned int xd, unsigned int ya, int ua) {
	AdditivesMap[xd][ya] = ua;
}

void Map::setBoard(unsigned int xd, unsigned int ya, int ua) {
	board[xd][ya] = ua;
}

void Map::CreateMap(int EndCivilian, int EndSoldier, int EndWeakZombie, int EndStrongZombie) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < 52; i++) cout << "\xDC";

	for (int p = 0; p < height; p++) {
		SetConsoleTextAttribute(hConsole, 7);
		cout << endl << "\xDB";
		for (int o = 0; o < width; o++)
		{
			if ((board[o][p] == 0) && (AdditivesMap[o][p] == 0)) { cout << "\40"; }
			else if (board[o][p] == 1) {
				SetConsoleTextAttribute(hConsole, 14);
				cout << "\3";
				SetConsoleTextAttribute(hConsole, 7);
			}

			else if (board[o][p] == 2) {
				SetConsoleTextAttribute(hConsole, 3);
				cout << "\4";
				SetConsoleTextAttribute(hConsole, 7);
			}

			else if ((board[o][p] == 3) && (AdditivesMap[o][p] == 0)) {
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\5";
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if ((board[o][p] == 3) && (AdditivesMap[o][p] == 5)) {
				SetConsoleTextAttribute(hConsole, 172);
				cout << "\5";
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if ((board[o][p] == 3) && (AdditivesMap[o][p] == 6)) {
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\5";
				SetConsoleTextAttribute(hConsole, 7);
			}

			else if ((board[o][p] == 4) && (AdditivesMap[o][p] == 0)) {
				SetConsoleTextAttribute(hConsole, 13);
				cout << "\6";
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if ((board[o][p] == 4) && (AdditivesMap[o][p] == 5)) {
				SetConsoleTextAttribute(hConsole, 173);
				cout << "\6";
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if ((board[o][p] == 4) && (AdditivesMap[o][p] == 6)) {
				SetConsoleTextAttribute(hConsole, 13);
				cout << "\6";
				SetConsoleTextAttribute(hConsole, 7);
			}

			else if ((board[o][p] == 0) && (AdditivesMap[o][p] == 5)) {
				SetConsoleTextAttribute(hConsole, 164);
				cout << "\40";
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if ((board[o][p] == 0) && (AdditivesMap[o][p] == 6)) {
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\30";
				SetConsoleTextAttribute(hConsole, 7);
			}
		}
		cout << "\xDB";

		if (p == 1) { cout << " Number of remaining people"; }
		else if (p == 2) { SetConsoleTextAttribute(hConsole, 14);  cout << "     Civilians :" << " \3 " << ": " << EndCivilian; }
		else if (p == 3) { SetConsoleTextAttribute(hConsole, 3);  cout << "     Soldiers :" << " \4 " << ": " << EndSoldier; SetConsoleTextAttribute(hConsole, 7); }
		else if (p == 4) { cout << " Number of remaining zombies"; }
		else if (p == 5) { SetConsoleTextAttribute(hConsole, 12);  cout << "     Weak zombies :" << " \5 " << ": " << EndWeakZombie; SetConsoleTextAttribute(hConsole, 7); }
		else if (p == 6) { SetConsoleTextAttribute(hConsole, 13); cout << "     Strong zombies :" << " \6 " << ": " << EndStrongZombie; }
		else if (p == 8) {
			SetConsoleTextAttribute(hConsole, 7);  cout << " Food : "; SetConsoleTextAttribute(hConsole, 175); cout << "\40";
		}
		else if (p == 9) { cout << " Weapon : " << "\30"; }
	}
	cout << endl;

	for (int i = 0; i < 52; i++) cout << "\xDF";
	cout << endl;
}

void Map::count(int& EndCivilian, int& EndSoldier, int& EndWeakZombie, int& EndStrongZombie, int& CurrentlyFood) {
	for (int i = 0; i < 50; i++) {
		for (int u = 0; u < 20; u++) {
			if (board[i][u] == 1) { EndCivilian++; }
			else if (board[i][u] == 2) { EndSoldier++; }
			else if (board[i][u] == 3) { EndWeakZombie++; }
			else if (board[i][u] == 4) { EndStrongZombie++; }
			else if (AdditivesMap[i][u] == 5) { CurrentlyFood++; }
		}
	}
}

void Map::Reducing(int& EndCivilian, int& EndSoldier, int& EndWeakZombie, int& EndStrongZombie, int& CurrentlyFood) {
	EndCivilian = 0;
	EndSoldier = 0;
	EndWeakZombie = 0;
	EndStrongZombie = 0;
	CurrentlyFood = 0;
}