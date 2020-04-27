#include <iostream>
#include <fstream>

#include <string>
#include "TemplatedMy_matrix.h"

using namespace std; 

int main(){
	//Test 1; creating Matrix 1 of type int and Matrix 2 of type double
	TemplatedMy_matrix<int> m1(2, 2);
	m1.elem(0, 0) = 1;
	m1.elem(0, 1) = 2;
	m1.elem(1, 0) = 3;
	m1.elem(1, 1) = 4;
	cout << "M1 of int: \n";
	cout << m1 << endl;
	
	TemplatedMy_matrix<double> m2(2, 2);
	m2.elem(0, 0) = 1.0;
	m2.elem(0, 1) = 2.0;
	m2.elem(1, 0) = 3.0;
	m2.elem(1, 1) = 4.0;
	cout << "M2 of double: \n";
	cout << m2 << endl;
	
	TemplatedMy_matrix<float> m3(2, 2);
	m3.elem(0, 0) = 1.0f;
	m3.elem(0, 1) = 2.0f;
	m3.elem(1, 0) = 3.0f;
	m3.elem(1, 1) = 4.0f;
	cout << "M3 of float: \n";
	cout << m3<< endl;

	TemplatedMy_matrix<int> m4(2, 3);
	m4.elem(0, 0) = 1;
	m4.elem(0, 1) = 2;
	m4.elem(0, 2) = 3;
	m4.elem(1, 0) = 4;
	m4.elem(1, 1) = 5;
	m4.elem(1, 2) = 6;
	cout << "M4 of int: \n";
	cout << m4 << endl;

	TemplatedMy_matrix<double> m5(2, 3);
	m5.elem(0, 0) = 1.0;
	m5.elem(0, 1) = 2.0;
	m5.elem(0, 2) = 3.0;
	m5.elem(1, 0) = 4.0;
	m5.elem(1, 1) = 5.0;
	m5.elem(1, 2) = 6.0;
	cout << "M5 of double: \n";
	cout << m5 << endl;

	TemplatedMy_matrix<float> m6(2, 3);
	m6.elem(0, 0) = 1.0f;
	m6.elem(0, 1) = 2.0f;
	m6.elem(0, 2) = 3.0f;
	m6.elem(1, 0) = 4.0f;
	m6.elem(1, 1) = 5.0f;
	m6.elem(1, 2) = 6.0f;
	cout << "M6 of float: \n";
	cout << m6 << endl;

	cout << "M1 + M1 = \n";
	cout << m1 + m1;

	cout << "M2 * M5 = \n";
	cout << m2 * m5;

	return 0;


}