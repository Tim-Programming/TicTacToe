#include <iostream>
#include "Play_field.h"
using namespace std;

int main()
{
	Play_field tik_tac_to_field;
	tik_tac_to_field.draw_field();

	Play_field another_play_field(7, 4);
	another_play_field.draw_field();

	return 0;
}
