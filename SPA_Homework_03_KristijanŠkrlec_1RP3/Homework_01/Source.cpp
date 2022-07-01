#include <iostream>
#include "Pathfinder.h"
#include <Windows.h>

using namespace std;

int main() {
	
	cout << "From (1, 1) to (20, 40) " << endl; 

	//Unos pocetnih i kranjih koordinata
	int X, Y;
	cout << "X(A): ";
	cin >> X;
	cout << "Y(A): ";
	cin >> Y;
	//Offset tako da ide da je 1 zapravo 0
	Dot A(X - 1, Y - 1, 'A');
	cout << "X(B): ";
	cin >> X;
	cout << "Y(B): ";
	cin >> Y;
	Dot B(X - 1, Y - 1, 'B');

	//Oznaka trenutne celije u konzoli 
	Dot dX(A.X, A.X, 'x');
	int counter = 0;

	//Inicijaliziranje pathfindera
	Pathfinder Path(A, B);

	//Udaljenost po X i Y
	pair<int, int> dist = dX.dist(B);
	cout << dist.first << " " << dist.second << endl;

	//Dok god X oznaka ne dodje do ending tocke
	while (dX.X != B.X || dX.Y != B.Y) {

		system("CLS");
		Path.cell(dX.X, dX.Y, dX.c);
		if (counter > 0) Path.cell(A.X, A.Y, 'A');

		Path.draw();

		Dot temp = dX;

		//X Axis distance checker
		if (dist.second > 0) {
			dX.Y++;
		}
		else if (dist.second < 0) {
			dX.Y--;
		}
		//Y Axis distance checker
		else if (dist.first > 0) {
			dX.X++;
		}
		else if (dist.first < 0) {
			dX.X--;
		}


		if (dX.X == B.X && dX.Y == B.Y) {
			Path.cell(B.X, B.X, 'dX');
			Path.cell(temp.X, temp.Y, '-');
			Sleep(75);
			system("CLS");
			Path.draw();
		}

		++counter;
		Path.cell(temp.X, temp.Y, '-');
		dist = dX.dist(B);
		Sleep(75);
	}


	cout << "Kristijan Škrlec, 1RP3" << endl; 
	cout << "\t\tit works good enough " << endl; 

	return 0;
}