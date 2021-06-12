#include <iostream>
#include "ArrangeData.h"
using namespace std;

void ArrangeData::LoadData(int& AmmountCivilians, int& AmmountSoldiers, int& AmmountWeakZombies, int& AmmountStrongZombie) {
    cout << "Enter the number of civilians (1 - 200): ";
    while (!(cin >> AmmountCivilians && AmmountCivilians <= 200 && AmmountCivilians >= 0)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout << "Incorrect number of Civilians. ";
    }

    cout << "Enter the number of soldiers (1 - 200): ";
    while (!(cin >> AmmountSoldiers && AmmountSoldiers <= 200 && AmmountSoldiers >= 0)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout << "Incorrect number of soldiers. ";
    }

    cout << "Enter the number of weak zombies (1 - 200): ";
    while (!(cin >> AmmountWeakZombies && AmmountWeakZombies <= 200 && AmmountWeakZombies >= 0)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout << "Incorrect number of weak zombies. ";
    }

    cout << "Enter the number of strong zombies (1 - 200): ";
    while (!(cin >> AmmountStrongZombie && AmmountStrongZombie <= 200 && AmmountStrongZombie >= 0)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout << "Incorrect number of strong zombies. ";
    }

}

void ArrangeData::LoadToFile(int AmmountCivilians, int AmmountSoldiers, int AmmountWeakZombies, int AmmountStrongZombie, int AmmountFood) {
    fstream plik;

    plik << "Initial value for each class" << endl;
    plik << "Civilians: " << AmmountCivilians << endl;
    plik << "Soldiers: " << AmmountSoldiers << endl;
    plik << "Weak Zombies: " << AmmountWeakZombies << endl;
    plik << "Strong Zombies: " << AmmountStrongZombie << endl;
    plik << "Food: " << AmmountFood << endl << endl;
    plik.close();
}

void ArrangeData::ShowData(int EndCivilians, int EndSoldier, int EndWeakZombie, int EndStrongZombie, int CurrentlyFood, int& z) {
    fstream plik;

    plik.open("dane.txt", ios::out | ios::app);
    plik << "Ammount of specimens in " << z++ << " round" << endl;
    plik << "Civilians: " << EndCivilians << endl;
    plik << "Soldiers: " << EndSoldier << endl;
    plik << "Weak Zombies: " << EndWeakZombie << endl;
    plik << "Strong Zombies: " << EndStrongZombie << endl;
    plik << "Ammount of food on the map: " << CurrentlyFood << endl << endl;
}