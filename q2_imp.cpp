#include "shapes.h"


int Shape::getlength()
	{
		return length;
	}
int Shape:: getwidth()
	{
		return width;
	}

void Shape::setlength(int l)
	{
		length = l;
	}
void Shape::setwidth(int w)
	{
		width = w;
	}
int Shape::getArea()
	{
		int x = length*width;
		return x;
	}
void Shape::rotateRectangle()
	{
		int swap;
		swap = length;
		length = width;
		width = swap;
	}
void Shape::draw()
{
	for (int i = 0 ; i < length ; i++)
	{
		for (int j = 0 ; j < width ; j++)
		{
				cout << "*";
		}
			cout << endl;
		}
}