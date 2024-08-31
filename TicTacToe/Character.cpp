#include "Character.h"

Character::Character()
{
	name = "None";
	short_symobl = 'x';
	id = 0;
	score = 0;
	Position position(-1, -1);
}

Character::Character(string name_in, char short_symbol_in, int id_in, int score_in, Position position_in) 
	: name(name_in), short_symobl(short_symbol_in), id(id_in), score(score_in), position(position_in)
{
}

void Character::set_name(string name)
{
	this->name = name;
}

void Character::set_short_symbol(char short_symbol)
{
	this->short_symobl = short_symbol;
}

void Character::set_id(int id)
{
	this->id = id;
}

void Character::set_score(int score)
{
	this->score = score;
}

void Character::set_position(Position position)
{
	this->position = position;
}

string Character::get_name()
{
	return this->name;
}

char Character::get_short_symbol()
{
	return this->short_symobl;
}

int Character::get_id()
{
	return this->id;
}

int Character::get_score()
{
	return this->score;
}

Position Character::get_position()
{
	return this->position;
}

int Character::get_x_coordinate()
{
	Position position;
	return this->position.get_x_coordinate();
}

int Character::get_y_coordinate()
{
	Position position;
	return this->position.get_y_coordinate();
}



