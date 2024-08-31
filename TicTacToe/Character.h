#pragma once
#include "common.h"
using namespace std;

class Character
{
private:
	string name;
	char short_symobl;
	int id;
	int score;
	Position position;
public:
	Character();
	Character(string name, char short_symbol, int id, int score, Position position);
	// Set-Methods
	void set_name(string name);
	void set_short_symbol(char short_symbol);
	void set_id(int id);
	void set_score(int score);
	void set_position(Position position);

	// Get-Methods
	string get_name();
	char get_short_symbol();
	int get_id();
	int get_score();
	Position get_position();
	int get_x_coordinate();
	int get_y_coordinate();
};

