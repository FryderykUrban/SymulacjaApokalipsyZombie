#include <iostream>
#include "Civilians.h"


using namespace std;

Civilians::Civilians(int ax, int ay, int c, int h, int td, bool he, bool die, int bn, int mv) {				//konstruktor
	Xpos = ax;
	Ypos = ay;
	capacity = c;
	Health = h;
	TakenDamage = td;
	Have = he;
	died = die;
	baseNumber = bn;
	move = mv;
}

void Civilians::Fight(int** board) {			// funkcja odpowiedzialna za walke
	if (((Ypos > 0) && (board[Xpos][Ypos - 1] == 3)) || ((Xpos > 0) && (board[Xpos - 1][Ypos] == 3)) || ((Ypos < 20) && (board[Xpos][Ypos + 1] == 3)) || ((Xpos < 49) && (board[Xpos + 1][Ypos] == 3))) {			// sprawdzenie czy wokol cywila nie ma slabego zombie
		TakenDamage = rand() % 14 + 1;				//losowe przydzielenia otrzymywanych obrazen

		for (int i = 0; i < TakenDamage; i++) {			// odjecie danej wartosci od zycia
			if (capacity > 0) { capacity--; }
			if (capacity <= 0) { Health--; }
		}
	}


	if (((Ypos > 0) && (board[Xpos][Ypos - 1] == 4)) || ((Xpos > 0) && (board[Xpos - 1][Ypos] == 4)) || ((Ypos < 20) && (board[Xpos][Ypos + 1] == 4)) || ((Xpos < 49) && (board[Xpos + 1][Ypos] == 4))) {			// sprawdzenie czy wokol cywila nie ma silnego zombie
		TakenDamage = rand() % 16 + 1;			//losowe przydzielenia otrzymywanych obrazen

		for (int i = 0; i < TakenDamage; i++) {			// odjecie danej wartosci od zycia
			if (capacity > 0) { capacity--; }
			if (capacity <= 0) { Health--; }
		}
	}
}

void Civilians::Multiplication(Civilians* Civil, int** board, int AmmountCivilians, int EndCivilians) {			// funkcja odpowiedzialna za rozmnazanie
	if (EndCivilians < AmmountCivilians) {			// sprawdzenie czy aktualna liczba cywili nie jest rowna od poczatkowej

		for (int i = 0; i < AmmountCivilians; i++) {
			bool Respawn = Civil[i].getDied();
			int health = Civil[i].getHealth();
			int xpos = Civil[i].getXpos();
			int ypos = Civil[i].getYpos();


			if ((Xpos < 49) && (Xpos > 1) && (Ypos < 19) && (Ypos > 1) && (capacity >= 6)) {			// warunek aby funkcja nie wyszla poza tablice
				if ((board[Xpos - 1][Ypos] == 1) || (board[Xpos + 1][Ypos] == 1) || (board[Xpos][Ypos - 1] == 1) || (board[Xpos][Ypos + 1] == 1) || (board[Xpos - 1][Ypos] == 2) || (board[Xpos + 1][Ypos] == 2) || (board[Xpos][Ypos - 1] == 2) || (board[Xpos][Ypos + 1] == 2)) {			// sprawdzenie czy przy cywilu znajduje sie czlowiek
					if ((Respawn == 1) && (board[xpos][ypos] == 0)) {
						Civil[i].setDied(Respawn - 1);			// przywrocenie zmarlego cywila do zycia
						Civil[i].setHealth(health + 20);
						board[xpos][ypos] = 1;

						capacity -= 6;			// odjecie od liczby capacity wymaganej ilosci jedzenia
						continue;
					}
				}
			}
		}
	}
}