#include <iostream>
#include "Civilians.h"


using namespace std;

Civilians::Civilians(int ax, int ay, int c, int h, int td, bool he, bool die, int bn, int mv) {
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

void Civilians::Fight(int** board) {
	if (((Ypos > 0) && (board[Xpos][Ypos - 1] == 3)) || ((Xpos > 0) && (board[Xpos - 1][Ypos] == 3)) || ((Ypos < 20) && (board[Xpos][Ypos + 1] == 3)) || ((Xpos < 49) && (board[Xpos + 1][Ypos] == 3))) {
		TakenDamage = rand() % 14 + 1;

		for (int i = 0; i < TakenDamage; i++) {
			if (capacity > 0) { capacity--; }
			if (capacity <= 0) { Health--; }
		}
	}


	if (((Ypos > 0) && (board[Xpos][Ypos - 1] == 4)) || ((Xpos > 0) && (board[Xpos - 1][Ypos] == 4)) || ((Ypos < 20) && (board[Xpos][Ypos + 1] == 4)) || ((Xpos < 49) && (board[Xpos + 1][Ypos] == 4))) {
		TakenDamage = rand() % 16 + 1;

		for (int i = 0; i < TakenDamage; i++) {
			if (capacity > 0) { capacity--; }
			if (capacity <= 0) { Health--; }
		}
	}
}

void Civilians::Multiplication(Civilians* Civil, int** board, int AmmountCivilians, int EndCivilians) {
	if (EndCivilians < AmmountCivilians) {

		for (int i = 0; i < AmmountCivilians; i++) {
			bool Respawn = Civil[i].getDied();
			int health = Civil[i].getHealth();
			int xpos = Civil[i].getXpos();
			int ypos = Civil[i].getYpos();


			if ((Xpos < 49) && (Xpos > 1) && (Ypos < 19) && (Ypos > 1) && (capacity >= 2)) {
				if ((board[Xpos - 1][Ypos] == 1) || (board[Xpos + 1][Ypos] == 1) || (board[Xpos][Ypos - 1] == 1) || (board[Xpos][Ypos + 1] == 1) || (board[Xpos - 1][Ypos] == 2) || (board[Xpos + 1][Ypos] == 2) || (board[Xpos][Ypos - 1] == 2) || (board[Xpos][Ypos + 1] == 2)) {
					if ((Respawn == 1) && (board[xpos][ypos] == 0)) {
						Civil[i].setDied(Respawn - 1);
						Civil[i].setHealth(health + 20);
						board[xpos][ypos] = 1;

						capacity -= 2;
						continue;
					}
				}
			}
		}
	}
}