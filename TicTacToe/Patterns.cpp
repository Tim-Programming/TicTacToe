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

bool Patterns::found_matches_horizontal(int number_of_boxes)
{
	this->match_horizontal = true;
	Play_field play_field;
	vector<Character> sorted_by_postion = play_field.sort_ascending_by_position(characters);
	vector<string> player_names = play_field.get_names_of_characters_in_play_field(sorted_by_postion);
	if (player_names.size() == 0)
	{
		this->match_horizontal = false;
		return false;
	}
	for (int i = 0; i < player_names.size(); i++)
	{
		int y_sum = 0;
		cout << player_names.at(i) << endl;
		vector<Character> sorted_by_name = play_field.get_all_Characters_with_same_name(player_names.at(i), sorted_by_postion);
		for (int j = 0; j < sorted_by_name.size(); j++)
		{
			y_sum += sorted_by_name.at(j).get_y_coordinate();
			if (j != sorted_by_name.at(j).get_x_coordinate())
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
	}
	return true;
}
