#include <iostream>
#include "matrix.h"

int main(int argc, char* argv[])
{
	std::cout << "Matrix" << std::endl;

	Matrix m = { {1,2,3,4},
				 {5,6,7,8},
				 {9,10,11,12} };

	std::cout << m.ToString();

	//std::cout << "\n" << m[1][2] << "\n\n";
	//m[1][2] = 3.14;
	//m.at(2,1) = 2.718281828;
	//m(0, 1) = 0.5;

	//std::cout << m.toString();

	Matrix m2 = { {1, 2, 3},
				  {4, 5, 6},
				  {7, 8, 9},
				  {10, 11, 12} };

	std::cout << "multiplication m x m2\n";
	std::cout << m.Multiplication(m2).ToString() << std::endl;
	std::cout << (m*m2).ToString() << std::endl;
	std::cout << m2.ToString() << std::endl;
	//m.Multiplication(m2);

	Matrix m0 = { {1,2} };
	Matrix m0t = { {1}, {2} };

	//std::cout << m0.toString() << "\n" << m0t.toString() << std::endl;
	std::cout << m0.ToString() << std::endl;
	std::cout << m0t.ToString() << std::endl;
	std::cout << m0.Multiplication(m0t).ToString() << std::endl;

	return 0;
}