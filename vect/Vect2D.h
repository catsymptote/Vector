#pragma once
class Vect2D
{
public:
	Vect2D();
	~Vect2D();

	float radius();
	void print();


private:
	int vct[2];


private:
	unsigned int size();
	void set(Vect2D &A);
	void setIndex(unsigned int index, float value);
	float getIndex(unsigned int index);

	


public:
	void operator = (Vect2D &A);

	friend Vect2D operator + (Vect2D &A, Vect2D &B);
	friend Vect2D operator - (Vect2D &A, Vect2D &B);
	friend float operator * (Vect2D &A, Vect2D &B);
	friend Vect2D operator % (Vect2D &A, Vect2D &B);

	friend Vect2D operator * (float, Vect2D &A);
	friend Vect2D operator / (float, Vect2D &A);

	float operator [] (unsigned int);
	
};
