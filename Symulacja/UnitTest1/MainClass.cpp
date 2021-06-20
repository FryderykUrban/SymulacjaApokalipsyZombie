#include <iostream>
#include "MainClass.h"

using namespace std;

void MainClass::ArrangeSpecimens(int** board) {			// rozmieszczenie ludzi i zombie na mapie
	int s = 0;

	while (true) {
		for (int o = 0; o < 50; o++) {
			for (int p = 0; p < 20; p++) {
				if (s == 1)  goto end;			// jezeli obiekt jest juz rozmieszczony petla sie konczy
				else if (!(rand() % 491) && (board[o][p] == 0)) {			// jezeli obiekt jeszcze nie jest romieszczony, wygenerowaa liczba jest podzielna przez 491 i wybrane pole jest puste
					board[o][p] = baseNumber;								// pojawia sie na nim obiek danej klasy
					Xpos = o;			// zapisywanie pozycji obiektu
					Ypos = p;
					s++;
				}
			}
		}
	}
end:
	s = 0;

}

void MainClass::ArrangeAdditives(int** board, int** AdditivesMap) {			//rozmieszczenie jedzenia i broni na mapie
	int f = 0;

	while (true) {
		for (int o = 0; o < 50; o++) {
			for (int p = 0; p < 20; p++) {
				if (f == 1)  goto end;			// jezeli obiekt jest juz rozmieszczony petla sie konczy
				else if (!(rand() % 491) && (AdditivesMap[o][p] == 0) && (board[o][p] == 0)) {			// jezeli obiekt jeszcze nie jest romieszczony, wygenerowaa liczba jest podzielna przez 491 i wybrane pole jest puste
					AdditivesMap[o][p] = baseNumber;													// pojawia sie na nim obiek danej klasy
					Xpos = o;			// zapisywanie pozycji obiektu
					Ypos = p;
					f++;
				}
			}
		}
	}
end:
	f = 0;
}

void MainClass::Movement(int** board) {
	move = rand() % 4 + 1;

	if ((board[Xpos][Ypos] == baseNumber) && (died == 0)) {

		if ((Ypos > 0) && (move == 1) && (board[Xpos][Ypos - 1] == 0)) {   // jezeli wygenerowana liczba rowna sie 1 obiekt porusza sie w do³
			board[Xpos][Ypos] = 0;
			board[Xpos][Ypos - 1] = baseNumber;
			Ypos--;
		}
		else if ((Xpos < 49) && (move == 2) && (board[Xpos + 1][Ypos] == 0)) {           // 2; prawo
			board[Xpos][Ypos] = 0;
			board[Xpos + 1][Ypos] = baseNumber;
			Xpos++;
		}
		else if ((Ypos < 20) && (move == 3) && (board[Xpos][Ypos + 1] == 0)) {           // 3; góra
			board[Xpos][Ypos] = 0;
			board[Xpos][Ypos + 1] = baseNumber;
			Ypos++;
		}
		else if ((Xpos > 0) && (move == 4) && (board[Xpos - 1][Ypos] == 0)) {                       // 4; lewo
			board[Xpos][Ypos] = 0;
			board[Xpos - 1][Ypos] = baseNumber;
			Xpos--;
		}
		else { board[Xpos][Ypos] = baseNumber; }
	}
}

int MainClass::getXpos()
{
	return Xpos;
}

int MainClass::getYpos()
{
	return Ypos;
}

int MainClass::getDied() {
	return died;
}

void MainClass::setXpos(int x)
{
	Xpos = x;
}

void MainClass::setYpos(int y)
{
	Ypos = y;
}

void MainClass::setDied(bool die) {
	died = die;
}

void MainClass::Dying(int** board) {
	if ((Health <= 0) && (board[Xpos][Ypos] == baseNumber) && (died == 0)) {			//zamienienie martwego obiektu na neutralny
		board[Xpos][Ypos] = 0;
		died = 1;
		Health = 0;
	}
}