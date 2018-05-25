#include "stdafx.h"
#include "Vector.h"
#include <string>
#include <iostream>
#include <cmath>


//Vector::Vector(unsigned int &dimention) : vct(new float[dimention]){};
Vector::Vector(const unsigned int dimention)
{
	this->vct = new float[dimention];
	this->dimention = dimention;
}

Vector::~Vector() {}

float Vector::radius()
{
	float rad = 0;
	for (unsigned int i = 0; i < this->dim(); i++)
		rad += pow(this->getIndex(i), 2);

	return sqrt(rad);

}

void Vector::print()
{
	// Print the vector in this format: [a, b, c]
	std::string out = "[";
	
	for (unsigned int i = 0; i < this->dim(); i++)
	{
		out += std::to_string(this->getIndex(i));
		if (i < this->dim() - 1)
			out += ", ";
	}
	out += "]";
	std::cout << out << std::endl;
}

unsigned int Vector::dim()
{
	return sizeof(this->vct);
}

void Vector::set(Vector &A)
{
	for (unsigned int i = 0; i < A.dim(); i++)
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
	Vector C(A.dim());
	if (A.dim() == B.dim())
		for (unsigned int i = 0; i < A.dim(); i++)
			C.setIndex(i, A[i] + B[i]);

	return C;
}

Vector operator-(Vector &A, Vector &B)
{
	// Vector subtraction
	for (unsigned int i = 0; i < A.dim(); i++)
		B.setIndex(i, -1 * B[i]);

	return (A + B);
}

float operator*(Vector &A, Vector &B)
{
	// Scalar product
	float scalar = 0;
	if (A.dim() != B.dim())
		return scalar;

	for (unsigned int i = 0; i < A.dim(); i++)
		scalar += A[i] * B[i];

	return scalar;
}

Vector operator%(Vector &A, Vector &B)
{
	// Cross product
	return Vector(2);
}

Vector operator*(float num, Vector &A)
{
	// Scalar * vector
	Vector C(A.dim());

	for (unsigned int i = 0; i < A.dim(); i++)
		C.setIndex(i, num * A[i]);

	return C;
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
