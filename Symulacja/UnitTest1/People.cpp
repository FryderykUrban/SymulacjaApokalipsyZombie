#include <iostream>
#include "People.h"

int People::getHave() {
	return Have;
}

int People::getHealth() {
	return Health;
}

void People::setHave(bool hve) {
	Have = hve;
}

void People::setHealth(int hlt) {
	Health = hlt;
}

void People::CollectingFood(int** AdditivesMap) {			//funkcja sprawdzaj¹ca odnalezienie jedzenia
	if (AdditivesMap[Xpos][Ypos] == 5) {
		AdditivesMap[Xpos][Ypos] = 0;

		int find = rand() % 4 + 1;			// wylosowanie iloœci hp która ma byc dodana do aktulanego zdrowia
		for (int i = 0; i < find; i++) {
			if (Health == 30) capacity++;
			if (Health < 30) Health++;
		}
	}
}

void People::Starving() {				//funkcja odejmujaca pkt zdrowia po kazdym ruchu 
	if (capacity > 0) { capacity -= 2; }
	else if (capacity <= 0) { Health -= 1; }
}

void People::Dying(int** board, int** AdditivesMap) {			// funkcja odpowiedzialna za usuniecie oiektu z mapy
	if ((Health <= 0) && (board[Xpos][Ypos] == baseNumber) && (died == 0)) {
		board[Xpos][Ypos] = 0;
		died = 1;			// jezeli died == 1 obiekt jest uznawany za zmarly

		if (Have == 1) { AdditivesMap[Xpos][Ypos] = 6; }			// po smierci obiektu zostaje bron jezeli takowa mial
	}
}

void People::CollectingWepons(int** AdditivesMap) {			// funkcja sprawdzaj¹ca odnalezienie broni
	if ((AdditivesMap[Xpos][Ypos] == 6) && (Have == 0)) {
		AdditivesMap[Xpos][Ypos] = 0;
		Have = 1;
	}
}