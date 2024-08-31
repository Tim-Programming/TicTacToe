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
                /*for (int k = 0; k < participating_characters.size(); k++)
                {
                    int x = participating_characters.at(k).get_x_coordinate();
                    int y = participating_characters.at(k).get_y_coordinate();
                    int x_play_field = ((j / this->box_width) * number_of_boxes) / number_of_boxes;
                    int y_play_field = ((i / this->box_width) * number_of_boxes) / number_of_boxes;
                    if ((x == x_play_field) and (y == y_play_field))
                    {
                        cout << participating_characters.at(k).get_short_symbol() << " ";
                        numbers.push_back(number);
                    }
                }
                for (int l = 0; l < numbers.size(); l++)
                {
                    if (number == numbers.at(l))
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
                    
                }*/
                for (int k = 0; k < participating_characters.size(); k++)
                {
                    int pos = convert_position(participating_characters.at(k).get_position());
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

void Play_field::show_all_characters() 
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

int Play_field::convert_position(Position position)
{
    int x = position.get_x_coordinate();
    int y = position.get_y_coordinate();
    return  x + (this->number_of_boxes) * y;
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
                    cout << "(" << position_old.get_x_coordinate() << "|" << position_old.get_y_coordinate() << ")" << endl;
                    cout << "Position exits already" << endl;
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