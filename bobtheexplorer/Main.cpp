//feat Laura Czaja i gwizdek
#include <iostream>
#include <random>
#include "fUnc.hpp"

using namespace std;

int main()
{
	char move;

	int Bx{1};
	int By{1}; //Bob's location

	int Fx{4};
	int Fy{4}; //Finish location
	cout << "Generowanie mapy..." << endl;
	//mt19937 generator(time(nullptr));
	//uniform_int_distribution <int> distribution(1, 4);
	//Bx = distribution(generator);
	//By = distribution(generator);
	//Fx = distribution(generator);
	//Fy = distribution(generator);
	//while (isFinish(Bx, By, Fx, Fy) == true)
	//{
	//	Bx = distribution(generator);
	//	By = distribution(generator);
	//	Fx = distribution(generator);
	//	Fy = distribution(generator);
	//}
	printmap(Bx, By, Fx, Fy);
	while (isFinish(Bx, By, Fx, Fy) != true)
	{
		cout << endl << "Ruch [w/a/s/d]: ";
		cin >> move;
		if (isMovePossible(move, Bx, By) == true)
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
			printmap(Bx, By, Fx, Fy);
		}
		else cout << "Ten ruch jest awykonalny xd" << endl;
	}
}
