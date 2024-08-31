#include <iostream>
#include "Play_field.h"
#include "Character.h"
#include "Patterns.h"
#include "common.h"
using namespace std;

int main()
{
	Play_field tik_tac_toe_field;

	Character player_a("player a", 'x', 0, 0, Position(0,2));
	Character player_b("player a", 'x', 1, 0, Position(2,2));
	Character player_c("player a", 'x', 2, 0, Position(1,2));
	Character player_d("player a", 'x', 0, 0, Position(3,2));
	Character player_e("player b", 'o', 1, 0, Position(1,1));
	Character player_f("player b", 'o', 0, 0, Position(2,1));
	tik_tac_toe_field.add_character(player_a);
	tik_tac_toe_field.add_character(player_b);
	tik_tac_toe_field.add_character(player_c);
	//tik_tac_toe_field.add_character(player_d);
	//tik_tac_toe_field.add_character(player_e);
	//tik_tac_toe_field.add_character(player_f);

	tik_tac_toe_field.draw_field();

	Patterns pattern;
	pattern.set_characters(tik_tac_toe_field.get_characters());
	bool result = pattern.found_matches_horizontal(tik_tac_toe_field.get_number_of_boxes());
	if (result)
	{
		cout << "match";
	}
	else
	{
		cout << "no match";
	}

	return 0;
}
