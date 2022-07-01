#pragma once
#include <utility>
#include <iostream>


using namespace std;

struct Dot {
	int X, Y;
	char c;

	Dot(int X, int Y, int c) {
		this->X = X;
		this->Y = Y;
		this->c = c;
	}



	pair<int, int> dist(Dot b) {
		pair<int, int> p;
		p.first = b.X - this->X;
		p.second = b.Y - this->Y;
		return p;
	}

};

class Pathfinder
{
private:
	char array[20][40];

public:
	Pathfinder(Dot begin, Dot end);
	void draw();
	bool is_empty(int i, int j);
	char get_char(int i, int j);
	void cell(int i, int j, char value);

};

