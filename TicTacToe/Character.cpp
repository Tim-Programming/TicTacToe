#include "Character.h"

Character::Character()
	: name("None"), short_symbol('x'), id(0), score(0), position(-1, -1)
{
}

Character::Character(string name_in, char short_symbol_in, int id_in, int score_in, Position position_in)
	: name(name_in), short_symbol(short_symbol_in), id(id_in), score(score_in), position(position_in)
{
}

// Setter
void Character::set_name(std::string name)
{
    this->name = name;
}

void Character::set_short_symbol(char short_symbol)
{
    this->short_symbol = short_symbol;
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

// Getter
std::string Character::get_name() const
{
    return this->name;
}

char Character::get_short_symbol() const
{
    return this->short_symbol;
}

int Character::get_id() const
{
    return this->id;
}

int Character::get_score() const
{
    return this->score;
}

Position Character::get_position() const
{
    return this->position;
}

int Character::get_x_coordinate() const
{
    return this->position.get_x_coordinate();
}

int Character::get_y_coordinate() const
{
    return this->position.get_y_coordinate();
}