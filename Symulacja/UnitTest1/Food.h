#pragma once
#include <iostream>
#include "MainClass.h"

using namespace std;

class Food : public MainClass {
public:
	Food(int = 1, int = 5, int = 5);
};