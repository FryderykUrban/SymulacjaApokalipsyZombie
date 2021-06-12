#include <iostream>
#include "Soldiers.h"

using namespace std;

Soldiers::Soldiers(int ax, int ay, int c, int h, int td, bool he, bool die, int bn, int mv) {
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

void Soldiers::Fight(int** board) {
	if (((Ypos > 0) && (board[Xpos][Ypos - 1] == 3)) || ((Xpos > 0) && (board[Xpos - 1][Ypos] == 3)) || ((Ypos < 20) && (board[Xpos][Ypos + 1] == 3)) || ((Xpos < 49) && (board[Xpos + 1][Ypos] == 3))) {
		TakenDamage = rand() % 8 + 1;

		for (int i = 0; i < TakenDamage; i++) {
			if (capacity > 0) { capacity--; }
			if (capacity <= 0) { Health--; }
		}
	}

	if (((Ypos > 0) && (board[Xpos][Ypos - 1] == 4)) || ((Xpos > 0) && (board[Xpos - 1][Ypos] == 4)) || ((Ypos < 20) && (board[Xpos][Ypos + 1] == 4)) || ((Xpos < 49) && (board[Xpos + 1][Ypos] == 4))) {
		TakenDamage = rand() % 9 + 1;

		for (int i = 0; i < TakenDamage; i++) {
			if (capacity > 0) { capacity--; }
			if (capacity <= 0) { Health--; }
		}
	}
}

void Soldiers::Multiplication(Soldiers* Soldier, int** board, int AmmountSoldiers, int EndSoldiers) {
	if (EndSoldiers < AmmountSoldiers) {
		for (int i = 0; i < AmmountSoldiers; i++) {
			bool Respawn = Soldier[i].getDied();
			int health = Soldier[i].getHealth();
			int xpos = Soldier[i].getXpos();
			int ypos = Soldier[i].getYpos();

			if ((Xpos < 49) && (Xpos > 1) && (Ypos < 19) && (Ypos > 1) && (capacity >= 2)) {
				if ((board[Xpos - 1][Ypos] == 1) || (board[Xpos + 1][Ypos] == 1) || (board[Xpos][Ypos - 1] == 1) || (board[Xpos][Ypos + 1] == 1) || (board[Xpos - 1][Ypos] == 2) || (board[Xpos + 1][Ypos] == 2) || (board[Xpos][Ypos - 1] == 2) || (board[Xpos][Ypos + 1] == 2)) {
					if (Respawn == 1) {
						Soldier[i].setDied(Respawn - 1);
						Soldier[i].setHealth(health + 20);
						board[xpos][ypos] = 2;
					}

					capacity -= 2;
					continue;
				}
			}
		}
	}
}