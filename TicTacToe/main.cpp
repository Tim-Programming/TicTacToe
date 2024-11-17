#include <iostream>
#include "Play_field.h"
#include "Character.h"
#include "Patterns.h"
#include "common.h"
using namespace std;

int get_play_field_size(int min_size, int max_size)
{
	cout << "Please choose the number of boxes" << endl;
	string number_of_boxes_string = "";
	int number_of_boxes = 0;
	do
	{
		getline(std::cin, number_of_boxes_string);
		number_of_boxes = stoi(number_of_boxes_string);
		if (number_of_boxes < min_size or number_of_boxes > max_size)
		{
			cout << "Only play field between " << min_size << " to " << max_size << "fields allowed!!!" << endl;
		}
	} while (number_of_boxes < min_size or number_of_boxes > max_size);
	return number_of_boxes;
}

int main()
{
	string name_of_player_a_as_string = "";
	string name_of_player_b_as_string = "";
	string position_player_a_as_string = "";
	string position_player_b_as_string = "";
	bool match_player_a = false;
	bool diagonal_player_a = false;
	bool horizontal_player_a = false;
	bool vertical_player_a = false;
	bool match_player_b = false;
	bool diagonal_player_b = false;
	bool horizontal_player_b = false;
	bool vertical_player_b = false;
	bool existing_pos = false;
	

	cout << "*****************************************************" << endl;
	cout << "*                                                   *" << endl;
	cout << "*              Welcome to Tic-Tac-Toe               *" << endl;
	cout << "*                                                   *" << endl;
	cout << "*****************************************************" << endl;

	int number_of_boxes = get_play_field_size(3, 6);

	Play_field tik_tac_toe_field(5, number_of_boxes);
	tik_tac_toe_field.draw_field();

	cout << "Player A. What would you like to be called?" << endl;
	getline(std::cin, name_of_player_a_as_string);
	cout << "Player " << name_of_player_a_as_string << " was added to the playground" << endl;

	cout << "Player B. What would you like to be called?" << endl;
	getline(std::cin, name_of_player_b_as_string);
	cout << "Player " << name_of_player_b_as_string << " was added to the playground" << endl;
	
	Patterns pattern;
	int play_round = 1;
	while (true)
	{
		cout << "Play round " << play_round << endl;

		// Player A
		do {
			cout << "Player " << name_of_player_a_as_string << ", it's your turn. Please type in a number." << endl;
			if (existing_pos) {
				cout << "This field is already set. Please choose another field!" << endl;
			}

			getline(std::cin, position_player_a_as_string);
			int pos_player_a_as_int = stoi(position_player_a_as_string);
			pos_player_a_as_int--;
			Position pos_player_a = tik_tac_toe_field.convert_number_into_x_y_position(pos_player_a_as_int);

			existing_pos = tik_tac_toe_field.is_position_occupied(pos_player_a); // Überprüfe, ob Position belegt ist

			if (!existing_pos) { // Nur hinzufügen, wenn die Position frei ist
				Character player_a("player a", 'x', play_round, 0, pos_player_a);
				tik_tac_toe_field.add_character(player_a); // Füge Charakter hinzu
				tik_tac_toe_field.draw_field();
			}

		} while (existing_pos);
		

		diagonal_player_a = pattern.found_matches_diagonal_for_player(tik_tac_toe_field.get_number_of_boxes(), tik_tac_toe_field.get_all_Characters_with_same_name("player a"));
		horizontal_player_a = pattern.found_matches_horizontal_for_player(tik_tac_toe_field.get_number_of_boxes(), tik_tac_toe_field.get_all_Characters_with_same_name("player a"));
		vertical_player_a = pattern.found_matches_vertical_for_player(tik_tac_toe_field.get_number_of_boxes(), tik_tac_toe_field.get_all_Characters_with_same_name("player a"));
		match_player_a = diagonal_player_a || horizontal_player_a || vertical_player_a;
		if (match_player_a)
		{
			cout << "Player " << name_of_player_a_as_string << " has won the game." << endl;
			break;
		}



		// Player B
		do {
			cout << "Player " << name_of_player_b_as_string << ", it's your turn. Please type in a number." << endl;
			if (existing_pos) {
				cout << "This field is already set. Please choose another field!" << endl;
			}

			getline(std::cin, position_player_b_as_string);
			int pos_player_b_as_int = stoi(position_player_b_as_string);
			pos_player_b_as_int--;
			Position pos_player_b = tik_tac_toe_field.convert_number_into_x_y_position(pos_player_b_as_int);

			existing_pos = tik_tac_toe_field.is_position_occupied(pos_player_b); // Überprüfe, ob Position belegt ist

			if (!existing_pos) { // Nur hinzufügen, wenn die Position frei ist
				Character player_b("player b", 'o', play_round, 0, pos_player_b);
				tik_tac_toe_field.add_character(player_b); // Füge Charakter hinzu
				tik_tac_toe_field.draw_field();
			}

		} while (existing_pos);

		diagonal_player_b = pattern.found_matches_diagonal_for_player(tik_tac_toe_field.get_number_of_boxes(), tik_tac_toe_field.get_all_Characters_with_same_name("player b"));
		horizontal_player_b = pattern.found_matches_horizontal_for_player(tik_tac_toe_field.get_number_of_boxes(), tik_tac_toe_field.get_all_Characters_with_same_name("player b"));
		vertical_player_b = pattern.found_matches_vertical_for_player(tik_tac_toe_field.get_number_of_boxes(), tik_tac_toe_field.get_all_Characters_with_same_name("player b"));
		match_player_b = diagonal_player_b || horizontal_player_b || vertical_player_b;
		if (match_player_b)
		{
			cout << "Player " << name_of_player_b_as_string << " has won the game." << endl;
			break;
		}
		
		play_round++;
	}

	return 0;
}
