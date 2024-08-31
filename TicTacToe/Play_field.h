#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "common.h"
using namespace std;

class Play_field
{
private:
	int box_width;
	int number_of_boxes;
	vector<Character> participating_characters;
public:
	Play_field();
	Play_field(int box_width, int number_of_boxes);
	void draw_field();
	void add_character(Character character);
	void show_all_characters();
	int convert_position(Position position);
	bool check_existing_position();
	bool check_equal_position(Position position_A, Position position_B);
};

