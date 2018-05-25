#pragma once
class Vector
{
public:
	Vector();
	~Vector();

	float radius();
	void print();


private:
	int vct[2];


private:
	unsigned int size();
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
