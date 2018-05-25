#include "stdafx.h"
#include "Vector.h"
#include <string>
#include <iostream>
#include <cmath>



Vector::Vector()
{

}


Vector::~Vector()
{

}

float Vector::radius()
{
	float rad = 0;
	for (int i = 0; i < this->size(); i++)
		rad += pow(this->getIndex(i), 2);

	return sqrt(rad);

}

void Vector::print()
{
	// Print the vector in this format: [a, b, c]
	std::string out = "[";
	
	for (int i = 0; i < this->size(); i++)
	{
		out += this->getIndex(i);
		if (i < this->size() - 1)
			out += ", ";
	}
	out += "]";
	std::cout << out << std::endl;
}

unsigned int Vector::size()
{
	return sizeof(this->vct);
}

void Vector::set(Vector &A)
{
	for (int i = 0; i < A.size(); i++)
		this->vct[i] = A[i];
}

void Vector::setIndex(unsigned int index, float value)
{
	this->vct[index] = value;
}

float Vector::getIndex(unsigned int index)
{
	return this->vct[index];
}

void Vector::operator=(Vector &A)
{
	// this = A
	this->set(A);
}

Vector operator+(Vector &A, Vector &B)
{
	// Vector addition
	Vector C;
	if (A.size() != B.size())
		return C;
	
	for (int i = 0; i < A.size(); i++)
		C.setIndex(i, A[i] + B[i]);

	return C;
}

Vector operator-(Vector &A, Vector &B)
{
	// Vector subtraction
	for (int i = 0; i < A.size(); i++)
		B.setIndex(i, -1 * B[i]);

	return (A + B);
}

float operator*(Vector &A, Vector &B)
{
	// Scalar product
	float scalar;
	if (A.size() != B.size())
		return scalar;

	for (int i = 0; i < A.size(); i++)
		scalar += A[i] * B[i];

	return scalar;
}

Vector operator%(Vector &A, Vector &B)
{
	// Cross product
	return Vector();
}

Vector operator*(float num, Vector &A)
{
	// Scalar * vector
	Vector C;

	for (int i = 0; i < A.size(); i++)
		C.setIndex(i, num * A[i]);

	return Vector();
}

Vector operator/(float num, Vector &A)
{
	// Scalar / vector
	return (1/num) * A;
}

float Vector::operator[](unsigned int index)
{
	// Get at index
	return this->vct[index];
}
