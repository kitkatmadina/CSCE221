/* 
Implementation of the clas My_matrix
*/

#include "My_matrix.h"
#include <stdexcept>

My_matrix::My_matrix() : n{ 0 }, m{ 0 }
{
  // add your code here
	ptr = nullptr;
}

void My_matrix::allocate_memory()
{
  // add your code here
	ptr = new int *[n];
	for (int i = 0; i < n; i++)
		ptr[i] = new int[m];
}

My_matrix::My_matrix(int n1, int m1) : n{ n1 },m{m1}
{
  // add your code here
	allocate_memory();
}

My_matrix::My_matrix(const My_matrix& mat)
{
  // add your code here
	n = mat.number_of_rows();
	m = mat.number_of_columns();
	ptr = new int*[n];
	for (int i = 0; i < n; i++)
		ptr[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			ptr[i][j] = mat.elem(i,j);
	}

}

// move constructor (optional)
My_matrix::My_matrix(My_matrix&& mat)
{
	// add your code here
	/*mat.n = 0;
	mat.m = 0;
	mat(0,0) = nullptr;*/

}

My_matrix::~My_matrix()
{
	// add your code here
	for (int i = 0; i < n; i++)
		delete[] ptr[i];
	delete[] ptr;
}

My_matrix& My_matrix::operator=(const My_matrix& mat)
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
			ptr[i][j] = mat.elem(i,j);
	}
	return *this;
}

// move assignment operator (optional)
My_matrix& My_matrix::operator=(My_matrix&& mat)
{
	// add your code here
	/*for (int i = 0; i < n; i++)
		delete[] ptr[i];
	delete[] ptr;
	n = mat.number_of_rows();
	m = mat.number_of_columns();
	ptr = mat(0,0);
	mat.n = 0;
	mat.m = 0;
	mat(0, 0) = nullptr;
	return *this;*/

}

int My_matrix::number_of_rows() const
{
	// add your code here
	return n;
}

int My_matrix::number_of_columns() const
{
	// add your code here
	return m;
}

int* My_matrix::operator()(int i) const
{
	// add your code here
	return ptr[i];
}

int My_matrix::operator()(int i, int j) const
{
	// add your code here
	return ptr[i][j];
}

int& My_matrix::operator()(int i, int j)
{
	// add your code here
	return ptr[i][j];
}

int My_matrix::elem(int i, int j) const
{
	if (i < 0 || i >= n) throw out_of_range("Out of range");
	if (j < 0 || j >= m) throw out_of_range("Out of range");
	// add your code here
	return ptr[i][j];
}

int& My_matrix::elem(int i, int j)
{
	// add your code here
	if (i < 0 || i >= n) throw out_of_range("Out of range");
	if (j < 0 || j >= m) throw out_of_range("Out of range");
	return ptr[i][j];
}

ostream& operator<<(ostream& out, const My_matrix& mat)
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

istream& operator>>(istream& in, My_matrix& mat)
{
	// add your code here
	for (int i = 0; i < mat.number_of_rows(); ++i){
		for (int j = 0; j < mat.number_of_columns(); ++j)
			in >> mat.elem(i, j);
	}
	return in;
	
}

My_matrix operator+(const My_matrix& mat1, const My_matrix& mat2)
{	My_matrix mat3(mat1.number_of_rows(), mat1.number_of_columns());
	if (mat1.number_of_rows() == mat2.number_of_rows() && mat1.number_of_columns() == mat2.number_of_columns()) {
		for (int i = 0; i < mat1.number_of_rows(); ++i){
			for (int j = 0; j < mat1.number_of_columns(); ++j) 
				mat3(i,j) = mat1(i,j) + mat2(i,j);
		}
		return mat3;
	}
	else {
		throw incompatible_matrices();
	}
}

My_matrix operator*(const My_matrix& mat1, const My_matrix& mat2)
{
  // add your code here
	My_matrix mat3(mat1.number_of_rows(), mat2.number_of_columns());
	if (mat1.number_of_columns() == mat2.number_of_rows()) {
		for (int i = 0; i < mat1.number_of_rows(); ++i) {
			for (int j = 0; j < mat2.number_of_columns(); ++j) {
				for (int k = 0; k < mat1.number_of_columns(); ++k) {
					mat3(i,j) += mat1(i,k) * mat2(k,j);
				}
			}
		}
		return mat3;
	}
	else {
		throw incompatible_matrices();
	}
}
