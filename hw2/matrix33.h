#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"


class matrix33 
{  


public:
	float matrix[3][3] ;
	vector3 x,y,z;
	float*ptr;
	
public:
	matrix33();
	matrix33(vector3 inA,vector3 inB,vector3 inC);
	matrix33(const matrix33 &m);
	
public:

	vector3                &operator [] (unsigned int index);
	
	matrix33               &operator =  (const matrix33 &m);
	matrix33               &operator += (const matrix33 &m);
	matrix33               &operator -= (const matrix33 &m);
	matrix33               &operator *= (float f);
	matrix33               &operator /= (float f);
	friend bool            operator == (const matrix33 &a, const matrix33 &b);
	friend bool            operator != (const matrix33 &a, const matrix33 &b);

	friend matrix33        operator - (const matrix33 &a);
	friend matrix33        operator + (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator - (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator * (const matrix33 &a, const matrix33 &b);
	friend matrix33        operator * (const matrix33 &m, float f);
	friend matrix33        operator * (float f, const matrix33 &m);
	friend matrix33        operator / (const matrix33 &m, float f);
	       
public:
	void set(vector3 AIn, vector3 BIn, vector3 CIn);
	
	void printMatrix()const;	
	
	matrix33 invert();
	
	float determinant();
	
	matrix33 identity();
};

#endif
