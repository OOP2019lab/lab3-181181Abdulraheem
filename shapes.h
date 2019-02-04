#include <iostream>
using namespace std;


class Shape
{
private:
		int length , width;

public:
	int getlength();
	int getwidth();
	int getArea();
	void setlength(int l);
	void setwidth(int w);
	void rotateRectangle();
	void draw();
};