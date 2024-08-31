#pragma once
#include "common.h"
#include "Character.h"
#include "Play_field.h"
class Patterns
{
private:
	bool match_horizontal;
	bool match_vertical;
	bool match_diagonal;
	vector<Character> characters;
public:
	Patterns();
	void set_characters(vector<Character> characters_in);
	void show_characters();
	bool found_matches_horizontal(int numberOf_boxes);
};

