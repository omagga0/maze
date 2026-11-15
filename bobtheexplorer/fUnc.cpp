#include <iostream>
#include "fUnc.hpp"
#include <algorithm>
#include <iomanip>

using namespace std;

bool isFinish(int Bx, int By, int Fx, int Fy) //warunek końca gry
{
	if (Bx == Fx && By == Fy)
		return true;
	else return false;
}

bool isMovePossible(char move, int Bx, int By) //sprawdza czy ruch jest możliwy poprzez symulacje tego ruchu
{

	switch (move)
	{
	case 'w':
		By--;
		break;
	case 's':
		By++;
		break;
	case 'a':
		Bx--;
		break;
	case 'd':
		Bx++;
		break;
	}

	for (int i = 0;i < 400;i++)
	{
			if (walls[i][0] == Bx && walls[i][1] == By)
				return false;
	}
	return true;
}

int printmap(int Bx, int By, int Fx, int Fy) //drukowanie mapy z aktualną lokalizacją obiektów
{
	int position = 0;
	bool isWall = false;
	for (int i = 0;i < 400;i++)
	{
		for (int j = 0;j < 36;j++)
		{
			if (walls[j][0] == tiles[i][0] && walls[j][1] == tiles[i][1] && isWall == false)
			{
				cout << setfill(' ') << setw(2) << '#';
				position++;
				isWall = true;
			}
		}
		if (Bx == tiles[i][0] && By == tiles[i][1] && isWall == false )
		{
			cout << setfill(' ') << setw(2) << 'B';
			position++;
		}
		else if (Fx == tiles[i][0] && Fy == tiles[i][1] && isWall == false)
		{
			cout << setfill(' ') << setw(2) << 'F';
			position++;
		}
		else
		{
			if (isWall == false)
			{
				cout << setfill(' ') << setw(2) << ' ';
				position++;
			}
		}
		if (position >= 20)
		{
			cout << '\n';
			position = 0;
		}
		isWall = false;
		
	}
	cout << '\n';
	return 0;
}