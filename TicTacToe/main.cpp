#include <iostream>
#include "Play_field.h"
#include "Character.h"
#include "Patterns.h"
#include "common.h"
using namespace std;

int get_valid_digit_input() {
	string input;
	do {
		cout << "Please enter a digit (or type 'exit' to quit): ";
		getline(cin, input);

		// Überprüfen, ob die Eingabe "exit" ist
		if (input == "exit") {
			cout << "Exiting the program." << endl;
			exit(0); // Programm beenden
		}

		// Überprüfen, ob die Eingabe nur eine Ziffer enthält
		if (input.size() == 1 && isdigit(input[0])) {
			return stoi(input); // Eingabe in Zahl konvertieren und zurückgeben
		}
		else {
			cout << "Invalid input. Please enter a single digit." << endl;
		}
	} while (true); // Wiederholen, bis eine gültige Eingabe vorliegt
}

int get_play_field_size(int min_size, int max_size)
{
	cout << "Please choose the number of boxes" << endl;
	string number_of_boxes_string = "";
	int number_of_boxes = 0;
	do
	{
		number_of_boxes = get_valid_digit_input();
		if (number_of_boxes < min_size or number_of_boxes > max_size)
		{
			cout << "Only play field between " << min_size << " to " << max_size << " fields allowed!!!" << endl;
		}
	} while (number_of_boxes < min_size or number_of_boxes > max_size);
	return number_of_boxes;
}

bool process_player_turn(
	const string& player_name,
	char player_symbol,
	int play_round,
	Play_field& tik_tac_toe_field,
	Patterns& pattern)
{
	bool existing_pos = false;
	string position_as_string;

	cout << "Play round " << play_round << endl;

	if (tik_tac_toe_field.are_all_fields_occupied()) {
		cout << "All fields are occupied. It's a tie!" << endl;
		return true; // Spiel ist vorbei
	}

	do {
		cout << "Player " << player_name << ", it's your turn. Please type in a number." << endl;
		if (existing_pos) {
			cout << "This field is already set. Please choose another field!" << endl;
		}

		int pos_as_int = get_valid_digit_input();
		pos_as_int--;
		Position pos = tik_tac_toe_field.convert_number_into_x_y_position(pos_as_int);

		existing_pos = tik_tac_toe_field.is_position_occupied(pos); // Überprüfe, ob Position belegt ist

		if (!existing_pos) { // Nur hinzufügen, wenn die Position frei ist
			Character player(player_name, player_symbol, play_round, 0, pos);
			tik_tac_toe_field.add_character(player); // Füge Charakter hinzu
			tik_tac_toe_field.draw_field();
		}

	} while (existing_pos);

	if (pattern.check_for_matches(
		tik_tac_toe_field.get_number_of_boxes(),
		tik_tac_toe_field.get_all_Characters_with_same_name(player_name)))
	{
		cout << "Player " << player_name << " has won the game." << endl;
		return true; // Spiel ist vorbei
	}

	return false; // Spiel geht weiter
}

int main()
{
	string name_of_player_a_as_string = "";
	string name_of_player_b_as_string = "";
	
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
	while (true) {
		if (process_player_turn(name_of_player_a_as_string, 'x', play_round, tik_tac_toe_field, pattern)) {
			break; // Spiel ist beendet
		}

		if (process_player_turn(name_of_player_b_as_string, 'o', play_round, tik_tac_toe_field, pattern)) {
			break; // Spiel ist beendet
		}

		play_round++; // Runde erhöhen
	}
	return 0;
}
