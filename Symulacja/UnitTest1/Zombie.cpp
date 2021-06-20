#include <iostream>
#include "Zombie.h"

using namespace std;


void Zombie::Fight(Soldiers* Soldier, Civilians* Civil, int** board, int AmmountCivilians, int AmmountSoldiers) {
    TakenDamage = 0;

    if (((Ypos > 0) && (board[Xpos][Ypos - 1] == 1)) || ((Xpos > 0) && (board[Xpos - 1][Ypos] == 1)) || ((Ypos < 20) && (board[Xpos][Ypos + 1] == 1)) || ((Xpos < 49) && (board[Xpos + 1][Ypos] == 1))) {           // sprawdzenie czy wokó³ zombie jest jakis cywil
        for (int i = 0; i < AmmountCivilians; i++) {
            int XposC = Civil[i].getXpos();
            int YposC = Civil[i].getYpos();
            bool AddDamage = Civil[i].getHave();

            if ((YposC > 0) && (YposC < 20) && (XposC > 0) && (XposC < 49))         // warunek aby funkcja nie wyszla poza granice tablicy
                if (((board[XposC - 1][YposC] == 3) || (board[XposC + 1][YposC] == 3) || (board[XposC][YposC - 1] == 3) || (board[XposC][YposC + 1] == 3)) || ((board[XposC - 1][YposC] == 4) || (board[XposC + 1][YposC] == 4) || (board[XposC][YposC - 1] == 4) || (board[XposC][YposC + 1] == 4))) {
                    if (AddDamage == 0) { TakenDamage = rand() % 6 + 1; }           // jezeli cywil nie ma broni 
                    else if (AddDamage == 1) { TakenDamage = (rand() % 6 + 1) + 5; }            // jezeli cywil ma bron

                    Health -= TakenDamage;
                    break;
                }
        }
    }

    if (((Ypos > 0) && (board[Xpos][Ypos - 1] == 2)) || ((Xpos > 0) && (board[Xpos - 1][Ypos] == 2)) || ((Ypos < 20) && (board[Xpos][Ypos + 1] == 2)) || ((Xpos < 49) && (board[Xpos + 1][Ypos] == 2))) {           // sprawdzenie czy wokol zombie jest jakis zolnierz
        for (int i = 0; i < AmmountSoldiers; i++) {
            int XposC = Soldier[i].getXpos();
            int YposC = Soldier[i].getYpos();
            bool AddDamage = Soldier[i].getHave();

            if ((YposC > 0) && (YposC < 20) && (XposC > 0) && (XposC < 49))         // warunek aby funkcja nie wyszla poza granice tablicy
                if (((board[XposC - 1][YposC] == 3) || (board[XposC + 1][YposC] == 3) || (board[XposC][YposC - 1] == 3) || (board[XposC][YposC + 1] == 3)) || ((board[XposC - 1][YposC] == 4) || (board[XposC + 1][YposC] == 4) || (board[XposC][YposC - 1] == 4) || (board[XposC][YposC + 1] == 4))) {
                    if (AddDamage == 0) { TakenDamage = rand() % 9 + 1; }           // jezeli zolnierz nie ma broni
                    else  if (AddDamage == 1) { TakenDamage = (rand() % 9 + 1) + 5; }           // jezeli zolnierz ma bron

                    Health -= TakenDamage;
                    break;
                }
        }
    }
}