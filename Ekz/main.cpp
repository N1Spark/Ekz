#include<iostream>
#include<Windows.h>
#include "Game.h"
using namespace std;

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do
	{
		Game startuem;
		startuem.start();
	} while (restart_game);
	return 0;
}