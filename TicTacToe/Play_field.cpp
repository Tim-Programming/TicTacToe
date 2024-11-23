#include "Play_field.h"

Play_field::Play_field() : box_width(5), number_of_boxes(3)
{
}

Play_field::Play_field(int box_width_in, int number_of_boxes_in) : box_width(box_width_in), number_of_boxes(number_of_boxes_in)
{
}

void Play_field::draw_field()
{
    cout << endl;
    int number = 1; // Startnummer für das erste Feld
    vector<int> numbers; // Liste von befüllten Feldern

    for (int i = 0; i < (this->box_width) * this->number_of_boxes - (this->number_of_boxes - 1); i++)
    {
        // Vertikale Schleife
        for (int j = 0; j < (this->box_width) * this->number_of_boxes - (this->number_of_boxes - 1); j++)
        {
            // Horizontale Schleife
            if (j % (this->box_width - 1) == 0 || i % (this->box_width - 1) == 0)
            {
                cout << "* ";
            }
            else if ((i % (this->box_width - 1) == (this->box_width - 1) / 2) && (j % (this->box_width - 1) == (this->box_width - 1) / 2))
            {
                bool found_character = false;
                // Überprüfen, ob ein Charakter auf der Position ist
                for (int k = 0; k < participating_characters.size(); k++)
                {
                    int pos = convert_x_y_position_into_number(participating_characters.at(k).get_position());
                    pos++;
                    if (pos == number)
                    {
                        cout << participating_characters.at(k).get_short_symbol() << " ";
                        found_character = true;
                        break;
                    }
                }

                if (!found_character)
                {
                    if (number < 10)
                    {
                        cout << number << " ";
                    }
                    else
                    {
                        cout << number;  // Ohne zusätzliches Leerzeichen für zweiziffrige Zahlen
                    }
                }

                number++; // Die Nummer für das nächste Feld erhöhen
            }
            else
            {
                cout << "  ";  // Leeres Feld
            }
        }
        cout << endl;
    }
}

void Play_field::add_character(Character character)
{
    this->participating_characters.push_back(character);
}

void Play_field::show_characters() 
{
    for (int i = 0; i < participating_characters.size(); i++)
    {
        cout << endl;
        cout << "**************************************************************************" << endl;
        cout << "player " << i << ". is: " << participating_characters.at(i).get_name() << endl;
        cout << "and has following attributes: " << endl;
        cout << "short name: " << participating_characters.at(i).get_short_symbol() << endl;
        cout << "id: " << participating_characters.at(i).get_id() << endl;
        cout << "score: " << participating_characters.at(i).get_score() << endl;
        cout << "Position: Pos(" << participating_characters.at(i).get_x_coordinate() << "|"<< participating_characters.at(i).get_y_coordinate() <<")"<< endl;
        cout << "**************************************************************************" << endl;
        cout << endl;
    }
}

void Play_field::show_characters(vector<Character> characters)
{
    for (int i = 0; i < characters.size(); i++)
    {
        cout << endl;
        cout << "**************************************************************************" << endl;
        cout << "player " << i << ". is: " << characters.at(i).get_name() << endl;
        cout << "and has following attributes: " << endl;
        cout << "short name: " << characters.at(i).get_short_symbol() << endl;
        cout << "id: " << characters.at(i).get_id() << endl;
        cout << "score: " << characters.at(i).get_score() << endl;
        cout << "Position: Pos(" << characters.at(i).get_x_coordinate() << "|" << characters.at(i).get_y_coordinate() << ")" << endl;
        cout << "**************************************************************************" << endl;
        cout << endl;
    }
}

int Play_field::convert_x_y_position_into_number(Position position)
{
    int x = position.get_x_coordinate();
    int y = position.get_y_coordinate();
    return  x + (this->number_of_boxes) * y;
}

Position Play_field::convert_number_into_x_y_position(int pos)
{
    int y = pos / this->number_of_boxes;
    int x = pos-(number_of_boxes * y);
    Position position(x,y);
    return position;
}

bool Play_field::is_position_occupied(Position position) {
    int pos_to_check = convert_x_y_position_into_number(position);
    for (const auto& character : participating_characters) {
        int existing_pos = convert_x_y_position_into_number(character.get_position());
        if (pos_to_check == existing_pos) {
            return true; // Position ist bereits belegt
        }
    }
    return false; // Position ist frei
}

bool Play_field::are_all_fields_occupied() const {
    // Anzahl der Felder im Spielfeld
    int total_fields = number_of_boxes * number_of_boxes;

    // Wenn die Anzahl der Charaktere gleich der Gesamtzahl der Felder ist, sind alle Felder belegt
    return participating_characters.size() == total_fields;
}

vector<Character> Play_field::get_all_Characters_with_same_name(string search_name)
{
    vector<Character> characters_by_name= {};
    for (int i = 0; i < this->participating_characters.size(); i++)
    {
        if (participating_characters.at(i).get_name() == search_name)
        {
            characters_by_name.push_back(participating_characters.at(i));
        }
       
    }
    return characters_by_name;
}

vector<Character> Play_field::get_all_Characters_with_same_name(string search_name, vector<Character> characters_in)
{
    vector<Character> characters_by_name = {};
    for (int i = 0; i < characters_in.size(); i++)
    {
        if (characters_in.at(i).get_name() == search_name)
        {
            characters_by_name.push_back(characters_in.at(i));
        }

    }
    return characters_by_name;
}

int Play_field::get_number_of_boxes()
{
    return this->number_of_boxes;
}

void Play_field::set_number_of_boxes(int boxes)
{
    this->number_of_boxes = boxes;
}

vector<Character> Play_field::get_characters()
{
    return this->participating_characters;
}

vector<string> Play_field::get_names_of_characters_in_play_field(vector<Character> characters) 
{
    vector<string> names;
    for (int i = 0; i < characters.size(); i++)
    {
        names.push_back(characters.at(i).get_name());
    }

    std::vector<string> list_without_multiple_occurrences = {};
    

    for (int j = 0; j < names.size(); j++)
    {
        string new_element = names.at(j);
        if (std::find(list_without_multiple_occurrences.begin(), list_without_multiple_occurrences.end(), new_element) != list_without_multiple_occurrences.end()) {
        }
        else {
            list_without_multiple_occurrences.push_back(new_element);
        }
    }

    return list_without_multiple_occurrences;
}