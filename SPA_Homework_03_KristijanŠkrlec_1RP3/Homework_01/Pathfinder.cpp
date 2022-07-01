#include "Pathfinder.h"
#include <iostream>


using namespace std;

Pathfinder::Pathfinder(Dot begin, Dot end)
{
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 40; ++j) {
			array[i][j] = '-';

		}
	}
	begin.c = 'x';
	end.c = 'B';
	array[begin.X][begin.Y] = begin.c;
	array[end.X][end.X] = end.c;
}

void Pathfinder::draw()
{
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 40; ++j) {
			cout << this->get_char(i, j);
			if (j == 39) cout << endl;

		}
	}
}

void Pathfinder::cell(int i, int j, char value)
{
	this->array[i][j] = value;
}

bool Pathfinder::is_empty(int i, int j)
{
	if (this->array[i][j] == '-') return true;
	return false;
}

char Pathfinder::get_char(int i, int j)
{
	return this->array[i][j];

}






