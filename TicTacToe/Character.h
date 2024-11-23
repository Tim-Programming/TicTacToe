#pragma once
#include "common.h"
using namespace std;

class Character
{
private:
	string name;
	char short_symbol;
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
	string get_name() const;
	char get_short_symbol() const;
	int get_id() const;
	int get_score() const;
	Position get_position() const;
	int get_x_coordinate() const;
	int get_y_coordinate() const;
};

