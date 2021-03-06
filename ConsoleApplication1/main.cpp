/* Author: Anderson Taylor
 * Date: 10/4/2018
 * File: main.cpp
 * Description: This file tests the functionality of the templated Vector class.
 */
#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	Vector<int> a;
	int num;
	
	cout << "Num of elements to push into the Vector? (push as many as you want but it will print the contents of the whole Vector after) ";
	cin >> num;

	for (int i = 0; i < num; i++) {
		a.push_back(i);
	}

	for (int i = 0; i < a.vec_size(); i++) {		// this loop alone shows that [] can access elements and it shows the size() is working.
		cout << a[i] << "  ";
	}

	cout << "\n^^ that proves that the [] operator can access elements now it will access i = 0 after using [] to change its value to 4.\n";

	a[0] = 4;
	cout << a[0] << endl;

	cout << "Now im printing the contents of a copied Vector using the = operator.\n";
	
	Vector<int> b;

	b = a;

	for (int i = 0; i < b.vec_size(); i++) {		// this loop prints b which is the same as a now.
		cout << b[i] << "  ";
	}

	cout << "\nNow to create a copy of b called c using the copy constructor and print it.\n";

	Vector<int> c(b);

	for (int i = 0; i < c.vec_size(); i++) {		// this loop prints c which is the same as a and b now.
		cout << c[i] << "  ";
	}

	cout << "\nNow to show that the templated class is working ill create a Vector of chars. (just going to use 'a')\n";

	Vector<char> d;

	for (int i = 0; i < num; i++) {
		d.push_back('a');
	}

	for (int i = 0; i < d.vec_size(); i++) {		// this loop prints d which is just the original Vector a's size but all 'a'.
		cout << d[i] << "  ";
	}

	return 0;
}
