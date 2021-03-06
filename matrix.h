#pragma once
#include <initializer_list>
#include <string>

class Matrix
{
	using T = double;
public:
	Matrix(size_t rows, size_t cols);
	Matrix(std::initializer_list<std::initializer_list<T>> data);
	Matrix(Matrix const& m);
	Matrix(Matrix&& m);
	~Matrix();

	Matrix& operator=(Matrix const&) = delete;
	Matrix& operator=(Matrix&&) = delete;

	Matrix Transpose() const;

	Matrix Addition(Matrix const& lhs) const;
	Matrix Subtraction(Matrix const& lhs) const;
	Matrix operator+(Matrix const& lhs) const;
	Matrix operator-(Matrix const& lhs) const;

	Matrix Multiplication(Matrix const& lhs) const;
	Matrix operator*(Matrix const& lhs) const;

	T& at(size_t row, size_t col) const;
	T& operator()(size_t row, size_t col) const;
	T* operator[](size_t row) const; 

	std::string ToString();
private:
	T* data;
	size_t rows, cols;
};