#include "common.h"

Position::Position() : x(-1), y(-1)
{
}

Position::Position(int x, int y) : x(x), y(y)
{
}

void Position::set_position(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Position::set_x_coordinate(int x)
{
	this->x = x;
}

void Position::set_y_coordinate(int y)
{
	this->y = y;
}

Position Position::get_position()
{
	return Position(this->x, this->y);
}

int Position::get_x_coordinate() const
{
	return this->x;
}

int Position::get_y_coordinate() const
{
	return this->y;
}
