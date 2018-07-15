#include "matrix.h"
#include <sstream> //ToString
#include<cassert> //Multiplication
#include<iostream>

Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(new Matrix::T[rows*cols]) {};

Matrix::Matrix(std::initializer_list<std::initializer_list<T>> data) : Matrix(data.size(), data.begin()->size())
{
	size_t i = 0;
	for(auto row : data) for(auto e : row) this->data[i++] = e;
}

Matrix::Matrix(Matrix&& m) : rows(m.rows), cols(m.cols), data(m.data)
{
	m.data = nullptr;
}

Matrix::~Matrix()
{
	if(data)
	{
		delete[] data;
		data = nullptr;
	}
}

Matrix Matrix::Transpose() const
{
	Matrix ret(cols, rows);

	for(size_t i = 0; i < rows; ++i) for(size_t j = 0; j < cols; ++j) ret(j,i) = at(i,j);

	return ret;
}

Matrix Matrix::Multiplication(Matrix const& lhs) const
{
	Matrix const& rhs = *this; 
	assert(rhs.cols == lhs.rows && "Dimension mismatch"); //TODO: possibly throw instead of assert
	Matrix ret(rhs.rows, lhs.cols);

	double sum{0};
	for(size_t r = 0; r < rhs.rows; ++r)
	{
		for(size_t c = 0; c < lhs.cols; ++c)
		{
			sum = 0;
			for(size_t i = 0; i < rhs.cols; ++i)
			{
				sum += rhs[r][i] * lhs[i][c];
			}
			ret[r][c] = sum;
		}
	}

	return ret;
}

Matrix Matrix::operator*(Matrix const& lhs) const
{
	return Multiplication(lhs);
}

Matrix::T& Matrix::at(size_t row, size_t col) const
{
	return data[row*cols + col];
}

Matrix::T& Matrix::operator()(size_t row, size_t col) const
{
	return at(row, col);
};

Matrix::T* Matrix::operator[](size_t row) const
{
	return data + row * cols;
}

std::string Matrix::ToString()
{
	std::ostringstream oss;
	
	auto line = [&](size_t i)
	{
		if(cols < 1) return;
		size_t j{0};
		for(; j < cols - 1; ++j) oss << at(i, j) << ", ";
		oss << at(i, j);
		return;
	};

	
	oss << "[ ";
	if(rows > 0)
	{
		size_t i = 0;
		line(i);
		if(rows > 1)
		{
			oss << "\n";
			while(++i < rows - 1)
			{
				oss << "  ", line(i), oss << "\n";
			}
			oss << "  ", line(i);
		}
	}	
	oss << " ]\n";

	return oss.str();
}