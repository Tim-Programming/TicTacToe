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

bool Patterns::found_matches_in_line(int number_of_boxes, vector<Character> characters, bool is_horizontal) {
	for (int i = 0; i < number_of_boxes; i++) {
		int consecutive_count = 0;

		for (int j = 0; j < number_of_boxes; j++) {
			Position current_pos = is_horizontal ? Position(j, i) : Position(i, j);

			bool found = std::any_of(characters.begin(), characters.end(),
				[&current_pos](const Character& character) {
					return character.get_position().get_x_coordinate() == current_pos.get_x_coordinate() &&
						character.get_position().get_y_coordinate() == current_pos.get_y_coordinate();
				});

			if (found) {
				consecutive_count++;
				if (consecutive_count == number_of_boxes) {
					return true; // Match gefunden
				}
			}
			else {
				consecutive_count = 0;
			}
		}
	}
	return false; // Kein Match gefunden
}


bool Patterns::found_matches_horizontal_for_player(int number_of_boxes, vector<Character> characters) {
	// Sortiere die Charaktere nach ihrer Position
	sort(characters.begin(), characters.end(), [](Character& a, Character& b) {
		return a.get_position().get_x_coordinate() < b.get_position().get_x_coordinate();
		});

	// Durchlaufe jede Zeile
	for (int row = 0; row < number_of_boxes; row++) {
		int consecutive_count = 0;

		// Durchlaufe jede Spalte der aktuellen Zeile
		for (int col = 0; col < number_of_boxes; col++) {
			Position current_pos(col, row);

			bool found = false;
			// Überprüfe, ob ein Charakter in der aktuellen Position ist
			for (auto& character : characters) {
				if (character.get_position().get_x_coordinate() == current_pos.get_x_coordinate() &&
					character.get_position().get_y_coordinate() == current_pos.get_y_coordinate()) {
					found = true;
					break;
				}
			}

			if (found) {
				consecutive_count++;
				if (consecutive_count == number_of_boxes) {
					return true; // Ein vollständiges Match wurde gefunden
				}
			}
			else {
				consecutive_count = 0; // Setze den Zähler zurück, wenn das aktuelle Feld nicht besetzt ist
			}
		}
	}
	return false; // Kein vollständiges horizontales Match gefunden
}

bool Patterns::found_matches_vertical_for_player(int number_of_boxes, vector<Character> characters) {
    return found_matches_in_line(number_of_boxes, characters, false);
}

bool Patterns::found_matches_diagonal_for_player(int number_of_boxes, vector<Character> characters) {
	// Überprüfe Hauptdiagonale (von oben links nach unten rechts)
	for (int start = 0; start < number_of_boxes; start++) {
		int consecutive_count = 0;

		// Diagonale von oben links nach unten rechts
		for (int row = start, col = 0; row < number_of_boxes && col < number_of_boxes; row++, col++) {
			Position current_pos(col, row);
			bool found = false;
			for (auto& character : characters) {
				if (character.get_position().get_x_coordinate() == current_pos.get_x_coordinate() &&
					character.get_position().get_y_coordinate() == current_pos.get_y_coordinate()) {
					found = true;
					break;
				}
			}

			if (found) {
				consecutive_count++;
				if (consecutive_count == number_of_boxes) {
					return true; // Match gefunden
				}
			}
			else {
				consecutive_count = 0;
			}
		}
	}

	// Überprüfe Nebendiagonale (von unten links nach oben rechts)
	for (int start = 1; start < number_of_boxes; start++) {
		int consecutive_count = 0;

		// Diagonale von unten links nach oben rechts
		for (int row = start, col = 0; row >= 0 && col < number_of_boxes; row--, col++) {
			Position current_pos(col, row);
			bool found = false;
			for (auto& character : characters) {
				if (character.get_position().get_x_coordinate() == current_pos.get_x_coordinate() &&
					character.get_position().get_y_coordinate() == current_pos.get_y_coordinate()) {
					found = true;
					break;
				}
			}

			if (found) {
				consecutive_count++;
				if (consecutive_count == number_of_boxes) {
					return true; // Match gefunden
				}
			}
			else {
				consecutive_count = 0;
			}
		}
	}
	return false; // Kein Match gefunden
}


