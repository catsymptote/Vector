#include "stdafx.h"
#include "Vect2D.h"
#include <string>
#include <iostream>
#include <cmath>



Vect2D::Vect2D()
{

}


Vect2D::~Vect2D()
{

}

float Vect2D::radius()
{
	float rad = 0;
	for (int i = 0; i < this->size(); i++)
		rad += pow(this->getIndex(i), 2);

	return sqrt(rad);

}

void Vect2D::print()
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

unsigned int Vect2D::size()
{
	return sizeof(this->vct);
}

void Vect2D::set(Vect2D &A)
{
	for (int i = 0; i < A.size(); i++)
		this->vct[i] = A[i];
}

void Vect2D::setIndex(unsigned int index, float value)
{
	this->vct[index] = value;
}

float Vect2D::getIndex(unsigned int index)
{
	return this->vct[index];
}

void Vect2D::operator=(Vect2D &A)
{
	// this = A
	this->set(A);
}

Vect2D operator+(Vect2D &A, Vect2D &B)
{
	// Vector addition
	Vect2D C;
	if (A.size() != B.size())
		return C;
	
	for (int i = 0; i < A.size(); i++)
		C.setIndex(i, A[i] + B[i]);

	return C;
}

Vect2D operator-(Vect2D &A, Vect2D &B)
{
	// Vector subtraction
	for (int i = 0; i < A.size(); i++)
		B.setIndex(i, -1 * B[i]);

	return (A + B);
}

float operator*(Vect2D &A, Vect2D &B)
{
	// Scalar product
	float scalar;
	if (A.size() != B.size())
		return scalar;

	for (int i = 0; i < A.size(); i++)
		scalar += A[i] * B[i];

	return scalar;
}

Vect2D operator%(Vect2D &A, Vect2D &B)
{
	// Cross product
	return Vect2D();
}

Vect2D operator*(float num, Vect2D &A)
{
	// Scalar * vector
	Vect2D C;

	for (int i = 0; i < A.size(); i++)
		C.setIndex(i, num * A[i]);

	return Vect2D();
}

Vect2D operator/(float num, Vect2D &A)
{
	// Scalar / vector
	return (1/num) * A;
}

float Vect2D::operator[](unsigned int index)
{
	// Get at index
	return this->vct[index];
}
