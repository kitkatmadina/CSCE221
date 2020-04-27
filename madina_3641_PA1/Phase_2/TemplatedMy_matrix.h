#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
// Definitions of user defined type exceptions 
struct invalid_input : public exception {
	virtual const char* what() const throw()
	{
		return "Invalid matrix input";
	}
};

struct incompatible_matrices : public exception {
	virtual const char* what() const throw()
	{
		return "Incompatible matrices";
	}
};

//Calling Temlated Matrix class
template<typename T>
class TemplatedMy_matrix {
	int n, m;// matrix dimensions
	T **ptr; // ptr to allocation, ptr[i][j] used to access elem;
	void allocate_memory();

public:
	TemplatedMy_matrix();  // default constructor
	TemplatedMy_matrix(int n1, int m1); // parameter constructor
	~TemplatedMy_matrix(); // destructor
	TemplatedMy_matrix(const TemplatedMy_matrix<T>& mat); // copy constructor
	TemplatedMy_matrix(TemplatedMy_matrix<T>&& mat);  // move constructor (optional)
	TemplatedMy_matrix<T>& operator=(const TemplatedMy_matrix<T>& mat); //copy assignment operator
	TemplatedMy_matrix<T>& operator=(TemplatedMy_matrix<T>&& mat); // move assignment operator (optional)
	int number_of_rows() const;
	int number_of_columns() const;
	T* operator()(int i) const; // overloaded to access to ith row
	T& operator()(int i, int j); // overloaded to access (i,j) element
	T operator()(int i, int j) const; // overloaded to access (i,j) element
	T elem(int i, int j) const; // overloaded to access (i,j) element
	T& elem(int i, int j); // overloaded to access (i,j) element
};
// see the handout for the description of these operators
template<typename T>
ostream& operator<<(ostream& out, const TemplatedMy_matrix<T>& mat);
template<typename T>
istream& operator>>(istream& in, TemplatedMy_matrix<T>& mat);
template<typename T>
TemplatedMy_matrix<T> operator+(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2);
template<typename T>
TemplatedMy_matrix<T> operator*(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2);

/*
Implementation of the class My_matrix
*/

template<typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix() : n{ 0 }, m{ 0 }
{
	// add your code here
	ptr = nullptr;
}
template<typename T>
void TemplatedMy_matrix<T>::allocate_memory()
{
	// add your code here
	ptr = new T *[n];
	for (int i = 0; i < n; i++)
		ptr[i] = new T[m];
}
template<typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix(int n1, int m1) : n{ n1 }, m{ m1 }
{
	// add your code here
	allocate_memory();
}
template<typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix(const TemplatedMy_matrix<T>& mat)
{
	// add your code here
	n = mat.number_of_rows();
	m = mat.number_of_columns();
	ptr = new T*[n];
	for (int i = 0; i < n; i++)
		ptr[i] = new T[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			ptr[i][j] = mat.elem(i, j);
	}

}


template<typename T>
// move constructor (optional)
TemplatedMy_matrix<T>::TemplatedMy_matrix(TemplatedMy_matrix<T>&& mat)
{
	// add your code here
	/*mat.n = 0;
	mat.m = 0;
	mat(0, 0) = nullptr;*/

}
template<typename T>
TemplatedMy_matrix<T>::~TemplatedMy_matrix()
{
	// add your code here
	for (int i = 0; i < n; i++)
		delete[] ptr[i];
	delete[] ptr;
}
template<typename T>
TemplatedMy_matrix<T>& TemplatedMy_matrix<T>::operator=(const TemplatedMy_matrix<T>& mat)
{
	// add your code here
	for (int i = 0; i < n; i++)
		delete[] ptr[i];
	delete[] ptr;
	n = mat.number_of_rows();
	m = mat.number_of_columns();
	ptr = new int*[n];
	for (int i = 0; i < n; i++)
		ptr[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			ptr[i][j] = mat.elem(i, j);
	}
	return *this;
}
template<typename T>
// move assignment operator (optional)
TemplatedMy_matrix<T>& TemplatedMy_matrix<T>::operator=(TemplatedMy_matrix<T>&& mat)
{
	// add your code here
	/*for (int i = 0; i < n; i++)
	delete[] ptr[i];
	delete[] ptr;
	n = mat.number_of_rows();
	m = mat.number_of_columns();
	ptr = mat(0, 0);
	mat.n = 0;
	mat.m = 0;
	mat(0, 0) = nullptr;
	return *this;*/

}
template<typename T>
int TemplatedMy_matrix<T>::number_of_rows() const
{
	// add your code here
	return n;
}
template<typename T>
int TemplatedMy_matrix<T>::number_of_columns() const
{
	// add your code here
	return m;
}
template<typename T>
T* TemplatedMy_matrix<T>::operator()(int i) const
{
	// add your code here
	return ptr[i];
}
template<typename T>
T TemplatedMy_matrix<T>::operator()(int i, int j) const
{
	// add your code here
	return ptr[i][j];
}
template<typename T>
T& TemplatedMy_matrix<T>::operator()(int i, int j)
{
	// add your code here
	return ptr[i][j];
}
template<typename T>
T TemplatedMy_matrix<T>::elem(int i, int j) const
{
	if (i < 0 || i >= n) throw out_of_range("Out of range");
	if (j < 0 || j >= m) throw out_of_range("Out of range");
	// add your code here
	return ptr[i][j];
}
template<typename T>
T& TemplatedMy_matrix<T>::elem(int i, int j)
{
	// add your code here
	if (i < 0 || i >= n) throw out_of_range("Out of range");
	if (j < 0 || j >= m) throw out_of_range("Out of range");
	return ptr[i][j];
}
template<typename T>
ostream& operator<<(ostream& out, const TemplatedMy_matrix<T>& mat)
{
	// add your code here
	for (int i = 0; i < mat.number_of_rows(); i++) {
		for (int j = 0; j < mat.number_of_columns(); j++) {
			out << mat.elem(i, j) << " ";
		}
		out << endl;
	}
	return out;
}
template<typename T>
istream& operator>>(istream& in, TemplatedMy_matrix<T>& mat)
{
	// add your code here
	for (int i = 0; i < mat.number_of_rows(); ++i) {
		for (int j = 0; j < mat.number_of_columns(); ++j)
			in >> mat.elem(i, j);
	}
	return in;

}
template<typename T>
TemplatedMy_matrix<T> operator+(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2)
{
	TemplatedMy_matrix<T> mat3(mat1.number_of_rows(), mat1.number_of_columns());
	if (mat1.number_of_rows() == mat2.number_of_rows() && mat1.number_of_columns() == mat2.number_of_columns()) {
		for (int i = 0; i < mat1.number_of_rows(); ++i) {
			for (int j = 0; j < mat1.number_of_columns(); ++j)
				mat3(i, j) = mat1(i, j) + mat2(i, j);
		}
		return mat3;
	}
	else {
		throw incompatible_matrices();
	}
}
template<typename T>
TemplatedMy_matrix<T> operator*(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2)
{
	// add your code here
	TemplatedMy_matrix<T> mat3(mat1.number_of_rows(), mat2.number_of_columns());
	if (mat1.number_of_columns() == mat2.number_of_rows()) {
		for (int i = 0; i < mat1.number_of_rows(); ++i) {
			for (int j = 0; j < mat2.number_of_columns(); ++j) {
				for (int k = 0; k < mat1.number_of_columns(); ++k) {
					mat3(i, j) += mat1(i, k) * mat2(k, j);
				}
			}
		}
		return mat3;
	}
	else {
		throw incompatible_matrices();
	}
}
