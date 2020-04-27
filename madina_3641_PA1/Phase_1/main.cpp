// main.cpp
// Tests all functionality of the class My_matrix class.

#include <iostream>
#include <fstream>
#include "My_matrix.h"
#include <string>
int main(){
  
  // Some test cases are expected to throw an exception.
  // Add more try and catch blocks as necessary for your code
  // to finish execution.
    
	try {

		// Test 1
		// * Create an object of type My_matrix, called m1, using constructor
		// * Initialize m1 in main (by assigning numbers to matrix elements)
		// * Display m1 on the screen using the operator <<
		cout << "Matrix m1: " << endl; 
		My_matrix m1(2, 2);
		m1.elem(0, 0) = 1;
		m1.elem(0, 1) = 2;
		m1.elem(1, 0) = 3;
		m1.elem(1, 1) = 4;
		cout << m1;

		// Test 2
		// * Create an object of type My_matrix, called m2, using (default)
		//   constructor
		// * Open an input file containing a matrix (row by row)
		// * Initialize m2 by reading from the input file using
		//   the operator >>
		// * Open an output file (can be empty)
		// * Write m2 to the output file using the operator <<
		string iname;
		string oname;
		cout << "Input file name: " << endl;
		cin >> iname;
		ifstream ifs(iname.c_str());
		if (!ifs) {
			cout << "cannot open input file " << iname << endl;
			throw invalid_input();
		}
		cout << "Output file name: " << endl;
		cin >> oname;
		ofstream ofs(oname.c_str());
		int a;
		int n;
		int m;
		ifs >> n >> m;
		My_matrix m2(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ifs >> a;
				m2.elem(i, j) = a;
			}
		}
		cout << "Outputting m2 from input file: "<< endl;
		cout << m2;
		cout << endl; 
		ofs << m2;
		// Test 3
		// * Use the copy constructor to make a copy of m1 called m3
		// * Apply the copy assignment to m1 called m4
		// * Display m3 and m4 on the screen using the operator <<
		My_matrix m3(m1);
		My_matrix m4 = m1;
		cout << "Matrix m3: " << endl;
		cout << m3 << endl;
		cout << "Matrix m4: " << endl;
		cout << m4 << endl;
		// Test 4
		// * Test the matrix multiplication operator (operator*)
		// * Apply the multiplication operator to valid and invalid cases
		// * Display the resulting matrix and its number of rows and columns
		cout << "Multiplying m1 * m1: " << endl;
		cout << m1 * m1 << endl;
		cout << "Multplying m1 + m2: " << endl;
		cout << m1 * m2;
	}
	catch (exception &error) {
		cerr << "Error: " << error.what() << endl;
	}
	try{
		My_matrix m1(2, 2);
		m1.elem(0, 0) = 1;
		m1.elem(0, 1) = 2;
		m1.elem(1, 0) = 3;
		m1.elem(1, 1) = 4;
		cout << "Matrix m1: " << m1 << endl;
		My_matrix m2(3, 2);
		m2.elem(0, 0) = 1;
		m2.elem(0, 1) = 2;
		m2.elem(1, 0) = 3;
		m2.elem(1, 1) = 4;
		m2.elem(2, 0) = 5;
		m2.elem(2, 1) = 6;
		cout << "Matrix m2: " << m2 << endl;
    // Test 5
    // * Test the matrix addition operator (operator+)
    // * Apply the multiplication operator to valid and invalid cases
    // * Display the resulting matrix and its number of rows and columns
		cout << "Adding m1 + m1: " << endl; 
		cout << m1 + m1<< endl;
		cout << "Adding m1 + m2: " << endl;
		cout << m1 + m2;
		return 0;
	} catch(exception &error){
    cerr << "Error: " << error.what() << endl;
	}
	return 0; 
}
