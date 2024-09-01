#pragma once
#include "common.h"
#include "Character.h"
#include "Play_field.h"
#include <tuple>
class Patterns
{
private:
	bool match_horizontal;
	bool match_vertical;
	bool match_diagonal;
	string match_player_name;
	vector<Character> characters;
public:
	Patterns();
	void set_characters(vector<Character> characters_in);
	void show_characters();
	bool found_matches_horizontal_for_player(int numberOf_boxes, vector<Character> characters);
	bool found_matches_vertical_for_player(int numberOf_boxes, vector<Character> characters);
	bool found_matches_diagonal_for_player(int numberOf_boxes, vector<Character> characters);
};

