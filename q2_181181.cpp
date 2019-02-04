// q2_181181.cpp : Defines the entry point for the console application.
//

#include "shapes.h"


int main()
{
	Shape a;
	int l , w ;
	cout << "Enter length: ";
	cin >> l;
	cout << "Enter width: ";
	cin >> w;
	a.setlength(l);
	a.setwidth(l);
	cout << "The length is: " << a.getlength() << endl;
	cout << "The width is: "<< a.getwidth()<< endl;
	cout << "The area is: ";
	cout << a.getArea()<<endl;
	a.draw();




	return 0;
}

