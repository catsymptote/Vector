#pragma once
class Vector
{
public:
	Vector(const unsigned int dimention);
	~Vector();
	
	float radius();
	void print();


private:
	unsigned int dimention;
	float* vct;


private:
	unsigned int dim();
	void set(Vector &A);
	void setIndex(unsigned int index, float value);
	float getIndex(unsigned int index);

	
public:
	void operator = (Vector &A);

	friend Vector operator + (Vector &A, Vector &B);
	friend Vector operator - (Vector &A, Vector &B);
	friend float operator * (Vector &A, Vector &B);
	friend Vector operator % (Vector &A, Vector &B);

	friend Vector operator * (float, Vector &A);
	friend Vector operator / (float, Vector &A);

	float operator [] (unsigned int);
	
};
