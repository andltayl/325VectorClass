/* Author: Anderson Taylor
 * Date: 4/23/2018
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
	
	cout << "Num of elements to push into the Vector? ";
	cin >> num;

	for (int i = 0; i < num; i++) {
		a.push_back(i);
		cout << "i " << i << "= " << a[i] << endl;
	}

	for (int i = 0; i < a.vec_size(); i++) {
		cout << a[i] << "  ";
	}
	return 0;
}
