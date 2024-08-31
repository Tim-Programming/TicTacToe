#include <iostream>
#include "Play_field.h"
#include "Character.h"
#include "common.h"
using namespace std;

int main()
{
	Play_field tik_tac_to_field;

	Character player_a("player a", '*', 0, 0, Position(0,0));
	Character player_b("player b", 'x', 0, 0, Position(1,1));
	Character player_d("player d", 'o', 0, 0, Position(0,0));
	tik_tac_to_field.add_character(player_a);
	tik_tac_to_field.add_character(player_b);
	tik_tac_to_field.add_character(player_d);

	tik_tac_to_field.show_all_characters();
	tik_tac_to_field.draw_field();

	return 0;
}
