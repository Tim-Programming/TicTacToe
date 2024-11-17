#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Position
{
private:
	int x;
	int y;
public:
	Position();
	Position(int x, int y);
	// Set-Methods
	void set_position(int x, int y);
	void set_x_coordinate(int x);
	void set_y_coordinate(int y);
	// Get-Methods
	Position get_position();
	int get_x_coordinate() const;
	int get_y_coordinate() const;
};

