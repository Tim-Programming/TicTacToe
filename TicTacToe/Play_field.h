#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "common.h"
#include <algorithm> // Für std::sort
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
	void show_characters();
	void show_characters(vector<Character> characters);
	int convert_x_y_position_into_number(Position position);
	Position convert_number_into_x_y_position(int pos);
	bool check_existing_position();
	bool check_equal_position(Position position_A, Position position_B);
	vector<Character> get_all_Characters_with_same_name(string search_name);
	vector<Character> sort_ascending_by_position(vector<Character> characters);
};
