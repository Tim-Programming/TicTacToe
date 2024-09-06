#include "Patterns.h"

Patterns::Patterns() 
	: match_horizontal(false), match_vertical(false), match_diagonal(false)
{
}

void Patterns::set_characters(vector<Character> characters_in)
{
	this->characters = characters_in;
}

void Patterns::show_characters()
{
	Play_field play_field;
	play_field.show_characters(characters);
}

bool Patterns::found_matches_horizontal_for_player(int number_of_boxes, vector<Character> characters_in)
{
	this->match_horizontal = true;
	Play_field play_field;
	vector<Character> sorted_by_postion = play_field.sort_ascending_by_position(characters_in);

	if (sorted_by_postion.size() == 0)
	{
		this->match_horizontal = false;
		return false;
	}

	int y_sum = 0;
	for (int j = 0; j < sorted_by_postion.size(); j++)
	{
		y_sum += sorted_by_postion.at(j).get_y_coordinate();
		if (j != sorted_by_postion.at(j).get_x_coordinate())
		{
			this->match_horizontal = false;
			return false;
		}
	}

	if (y_sum % number_of_boxes != 0)
	{
		this->match_horizontal = false;
		return false;
	}

	return true;
}


bool Patterns::found_matches_vertical_for_player(int number_of_boxes, vector<Character> characters_in)
{
	this->match_vertical = true;
	Play_field play_field;
	vector<Character> sorted_by_postion = play_field.sort_ascending_by_position(characters_in);

	if (sorted_by_postion.size() == 0)
	{
		this->match_vertical = false;
		return false;
	}

	int x_sum = 0;
	for (int j = 0; j < sorted_by_postion.size(); j++)
	{
		x_sum += sorted_by_postion.at(j).get_x_coordinate();
		if (j != sorted_by_postion.at(j).get_y_coordinate())
		{
			this->match_vertical = false;
			return false;
		}
	}

	if (x_sum % number_of_boxes != 0)
	{
		this->match_vertical = false;
		return false;
	}

	return true;
}
bool Patterns::found_matches_diagonal_for_player(int number_of_boxes, vector<Character> characters_in)
{
	this->match_diagonal = true;
	Play_field play_field;
	vector<Character> sorted_by_position = play_field.sort_ascending_by_position(characters_in);

	if (sorted_by_position.size() == 0)
	{
		this->match_diagonal = false;
		return false;
	}

	// Check for top-left to bottom-right diagonal
	bool top_left_to_bottom_right = true;
	for (int j = 0; j < number_of_boxes; j++)
	{
		bool found = false;
		for (auto& character : sorted_by_position)
		{
			if (character.get_x_coordinate() == j && character.get_y_coordinate() == j)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			top_left_to_bottom_right = false;
			break;
		}
	}

	// Check for top-right to bottom-left diagonal
	bool top_right_to_bottom_left = true;
	for (int j = 0; j < number_of_boxes; j++)
	{
		bool found = false;
		for (auto& character : sorted_by_position)
		{
			if (character.get_x_coordinate() == j && character.get_y_coordinate() == number_of_boxes - 1 - j)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			top_right_to_bottom_left = false;
			break;
		}
	}

	if (!top_left_to_bottom_right && !top_right_to_bottom_left)
	{
		this->match_diagonal = false;
		return false;
	}

	return true;
}

