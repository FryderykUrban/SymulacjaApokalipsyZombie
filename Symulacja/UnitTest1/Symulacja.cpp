#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>
#include <thread>
#include "Map.h"
#include "MainClass.h"
#include "ArrangeData.h"

using namespace std;

int main()
{
    srand((unsigned int)time(NULL));         // generator liczb pseudolosowych

    int AmmountCivilians = 0, AmmountSoldiers = 0;
    int AmmountWeakZombies = 0, AmmountStrongZombie = 0;
    int EndCivilians = 0;
    int EndSoldier = 0;
    int EndWeakZombie = 0;
    int EndStrongZombie = 0;
    int CurrentlyFood = 0;
    int z = 1;

    fstream plik;
    plik.open("dane.txt", ios::out);            // rozpoczęcie zapisu do pliku

    ArrangeData::LoadData(AmmountCivilians, AmmountSoldiers, AmmountWeakZombies, AmmountStrongZombie);          // wczytanie poczatkowych wartosci ludzi i zombie

    int AmmountFood = 0;
    if (AmmountCivilians + AmmountSoldiers >= 30) { AmmountFood = 20; }
    else { AmmountFood = 10; }
    int AmmmountWeapons = 10;

    ArrangeData::LoadToFile(AmmountCivilians, AmmountSoldiers, AmmountWeakZombies, AmmountStrongZombie, AmmountFood);           // zapis do pliku

    Map m1;             // utworzenie obiektu mapy board i AdditivesMap
    int** AdditivesMap = m1.getArrayAdditivesMap();
    int** board = m1.getBoard();

    Civilians* Civil = new Civilians[AmmountCivilians];         // utworzenie wskaznika na tablice obiektow klasy Civilians
    for (int i = 0; i < AmmountCivilians; i++)
    {
        Civil[i] = Civilians(1, 1, AmmountCivilians);
    }

    Soldiers* Soldier = new Soldiers[AmmountSoldiers];          // Soldiers
    for (int o = 0; o < AmmountSoldiers; o++)
    {
        Soldier[o] = Soldiers(1, 1, AmmountSoldiers);
    }

    WeakZombies* WeakZombie = new WeakZombies[AmmountWeakZombies];          // WeakZombie
    for (int p = 0; p < AmmountWeakZombies; p++)
    {
        WeakZombie[p] = WeakZombies(1, 1, AmmountWeakZombies);
    }

    StrongZombies* StrongZombie = new StrongZombies[AmmountStrongZombie];           // StrongZombie
    for (int k = 0; k < AmmountStrongZombie; k++)
    {
        StrongZombie[k] = StrongZombies(1, 1, AmmountStrongZombie);
    }

    Food* food = new Food[AmmountFood];         // Food
    for (int q = 0; q < AmmountFood; q++)
    {
        food[q] = Food(1, AmmountFood);
    }

    Weapons* Weapon = new Weapons[AmmmountWeapons];         //Weapons
    for (int v = 0; v < AmmmountWeapons; v++)
    {
        Weapon[v] = Weapons(1, AmmmountWeapons);
    }

    for (int pks = 0; pks < AmmountCivilians; pks++) { Civil[pks].ArrangeSpecimens(board); }            // rozmieszczenie obiektow na mapie
    for (int pks = 0; pks < AmmountSoldiers; pks++) { Soldier[pks].ArrangeSpecimens(board); }
    for (int pks = 0; pks < AmmountWeakZombies; pks++) { WeakZombie[pks].ArrangeSpecimens(board); }
    for (int pks = 0; pks < AmmountStrongZombie; pks++) { StrongZombie[pks].ArrangeSpecimens(board); }
    for (int i = 0; i < AmmountFood; i++) { food[i].ArrangeAdditives(board, AdditivesMap); }
    for (int i = 0; i < AmmmountWeapons; i++) { Weapon[i].ArrangeAdditives(board, AdditivesMap); }

    this_thread::sleep_for(500ms);
    system("cls");

    while (true) {
        m1.Reducing(EndCivilians, EndSoldier, EndWeakZombie, EndStrongZombie, CurrentlyFood);           // zredukowanie do zera zmiennych zliczajacych aktualna liczbe obiektow na mapie
        for (int dnf = 0; dnf < AmmountCivilians; dnf++) {
            Civil[dnf].Dying(board, AdditivesMap);          // funkcja jest odpowiedzialna za usuwanie obiektow z mapy
            Civil[dnf].Movement(board);         // funkcja odpowiedzialna za poruszanie sie obiektow
            Civil[dnf].Fight(board);            // funkcja odpowiedzialna za otrzymywanie obrazen 
            Civil[dnf].CollectingFood(AdditivesMap);            // funkcja odpowiedzialna za zbieranie jedzenia
            Civil[dnf].CollectingWepons(AdditivesMap);          // funkcja odpowiadająca za podnoszenie broni 
            Civil[dnf].Starving();          // funkcja zagładzająca kurwy 
            Civil[dnf].Multiplication(Civil, board, AmmountCivilians, EndCivilians);            //funkcja rozmnazania
        }

        for (int pks = 0; pks < AmmountSoldiers; pks++) {
            Soldier[pks].Dying(board, AdditivesMap);
            Soldier[pks].Movement(board);
            Soldier[pks].Fight(board);
            Soldier[pks].CollectingFood(AdditivesMap);
            Soldier[pks].CollectingWepons(AdditivesMap);
            Soldier[pks].Starving();
            Soldier[pks].Multiplication(Soldier, board, AmmountSoldiers, EndSoldier);
        }

        for (int rks = 0; rks < AmmountWeakZombies; rks++) {
            WeakZombie[rks].Dying(board);
            WeakZombie[rks].Movement(board);
            WeakZombie[rks].Fight(Soldier, Civil, board, AmmountCivilians, AmmountSoldiers);
        }

        for (int dns = 0; dns < AmmountStrongZombie; dns++) {
            StrongZombie[dns].Dying(board);
            StrongZombie[dns].Movement(board);
            StrongZombie[dns].Fight(Soldier, Civil, board, AmmountCivilians, AmmountSoldiers);
        }

        m1.count(EndCivilians, EndSoldier, EndWeakZombie, EndStrongZombie, CurrentlyFood);          //funkcja zlicza obiekty znajdujace sie na mapie
        food->ArrangeAdditives(board, AdditivesMap);            //dodawanie jednego jedzenia co ture
        m1.CreateMap(EndCivilians, EndSoldier, EndWeakZombie, EndStrongZombie);

        this_thread::sleep_for(500ms); // uspienie programu na 0,5s
        system("cls");                  // oczyszczenie konsoli

        ArrangeData::ShowData(EndCivilians, EndSoldier, EndWeakZombie, EndStrongZombie, CurrentlyFood, z);      // zapisywanie danych do pliku

        if ((EndSoldier + EndCivilians) <= 0) { cout << "Zombies won."; break; }            // warunki konczace symulacje
        if ((EndWeakZombie + EndStrongZombie) <= 0) { cout << "People won."; break; }

        plik.close();
    }
    return 0;
}
