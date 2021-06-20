#include <iostream>
#include <fstream>

class ArrangeData {
public:
	static void LoadData(int& AmmountCivilians, int& AmmountSoldiers, int& AmmountWeakZombies, int& AmmountStrongZombie);
	static void LoadToFile(int AmmountCivilians, int AmmountSoldiers, int AmmountWeakZombies, int AmmountStrongZombie, int AmmountFood);
	static void ShowData(int EndCivilians, int EndSoldier, int EndWeakZombie, int EndStrongZombie, int CurrentlyFood, int& z);
};