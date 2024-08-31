#include <iostream>
#include "Play_field.h"
#include "Character.h"
#include "common.h"
using namespace std;

int main()
{
	Play_field tik_tac_toe_field;

	Character player_a("player a", 'x', 0, 0, Position(0,0));
	Character player_b("player a", 'x', 1, 0, Position(2,0));
	Character player_c("player a", 'x', 2, 0, Position(1,0));
	Character player_d("player b", 'o', 0, 0, Position(0,1));
	Character player_e("player b", 'o', 1, 0, Position(1,1));
	Character player_f("player b", 'o', 0, 0, Position(2,1));
	tik_tac_toe_field.add_character(player_a);
	tik_tac_toe_field.add_character(player_b);
	tik_tac_toe_field.add_character(player_c);
	tik_tac_toe_field.add_character(player_d);
	tik_tac_toe_field.add_character(player_e);
	tik_tac_toe_field.add_character(player_f);

	tik_tac_toe_field.draw_field();

	vector<Character> characters_by_name = tik_tac_toe_field.get_all_Characters_with_same_name("player a");
	tik_tac_toe_field.show_characters(characters_by_name);
	vector<Character> characters_sort_by_position = tik_tac_toe_field.sort_ascending_by_position(characters_by_name);
	tik_tac_toe_field.show_characters(characters_sort_by_position);


	return 0;
}
