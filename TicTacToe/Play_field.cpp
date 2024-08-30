#include "Play_field.h"

Play_field::Play_field() : box_width(5), number_of_boxes(3)
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
