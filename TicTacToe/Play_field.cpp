#include "Play_field.h"

Play_field::Play_field() : box_width(5), number_of_boxes(3)
{
}

Play_field::Play_field(int box_width_in, int number_of_boxes_in) : box_width(box_width_in), number_of_boxes(number_of_boxes_in)
{
}

void Play_field::draw_field()
{
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
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
