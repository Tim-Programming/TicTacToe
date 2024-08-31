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
    int number = 0;
    vector<int> numbers = {};
    bool flag_found_character = false;

    for (int i = 0; i < (this->box_width)*this->number_of_boxes - (this->number_of_boxes - 1); i++)
    {
        // vertical
        for (int j = 0; j < (this->box_width)*this->number_of_boxes - (this->number_of_boxes - 1); j++)
        {
            // horizontal
            if (j % (this->box_width - 1) == 0 || i % (this->box_width - 1) == 0)
            {
                cout << "* ";
            }
            
            else if ((i % (this->box_width - 1) == (this->box_width - 1) / 2) && (j % (this->box_width - 1) == (this->box_width - 1) / 2))
            {
                for (int k = 0; k < participating_characters.size(); k++)
                {
                    int pos = convert_x_y_position_into_number(participating_characters.at(k).get_position());
                    if (pos == number)
                    {
                        cout << participating_characters.at(k).get_short_symbol() << " ";
                        numbers.push_back(number);
                    }
                }
                for (int l = 0; l < numbers.size(); l++)
                {
                    if (numbers.at(l) == number)
                    {
                        flag_found_character = true;
                    }
                    else
                    {
                        flag_found_character = false;
                    }
                }
                if (!flag_found_character)
                {
                    if (number >= 10 - 1)
                    {
                        cout << number + 1 << "";
                    }
                    else
                    {
                        cout << number + 1 << " ";
                    }
                }
                number++;
            }
            else
            {
                cout << "  ";
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


bool Play_field::check_existing_position()
{
    for (int i = 0; i < this->participating_characters.size(); i++)
    { 
        Position position_old = participating_characters.at(i).get_position();
        for (int j = 0; j < this->participating_characters.size(); j++)
        {
            if (i != j)
            {
                Position position_new = participating_characters.at(j).get_position();
                bool equaltiy = check_equal_position(position_old, position_new);
                if (check_equal_position(position_old, position_new))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Play_field::check_equal_position(Position position_A, Position position_B)
{
    return(position_A.get_x_coordinate() == position_B.get_x_coordinate() and position_A.get_y_coordinate() == position_B.get_y_coordinate());
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


vector<Character> Play_field::sort_ascending_by_position(vector<Character> characters)
{
    // Hilfsfunktion zum Vergleichen der Positionen
    struct ComparePositions {
        Play_field* play_field;
        ComparePositions(Play_field* pf) : play_field(pf) {}

        bool operator()(Character& a, Character& b) {
            return play_field->convert_x_y_position_into_number(a.get_position()) < play_field->convert_x_y_position_into_number(b.get_position());
        }
    };

    // Sortieren des Vektors
    std::sort(characters.begin(), characters.end(), ComparePositions(this));

    return characters;
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