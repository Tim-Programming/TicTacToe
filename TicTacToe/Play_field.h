#pragma once
#include <iostream>
using namespace std;

class Play_field
{
private:
	int box_width;
	int number_of_boxes;
public:
	Play_field();
	void draw_field();
};

