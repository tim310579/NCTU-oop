#include "matrix33.h"
#include <iostream>
#include "math.h"
#include "vector3.h"

using namespace std;
matrix33::matrix33(){
}
matrix33::matrix33(vector3 inA ,vector3 inB ,vector3 inC){
	x.x= inA.x;
	x.y= inA.y;
	x.z= inA.z;
	y.x= inB.x;
	y.y= inB.y;
	y.z= inB.z;
	z.x= inC.x;
	z.y= inC.y;
	z.z= inC.z;
}
matrix33::matrix33(const matrix33 &m){
	x= m.x;
	y= m.y;
	z= m.z;
	
}
 vector3 & matrix33::operator[](unsigned int index){
	if (index==0) {
  		return x;
	}
	else if (index==1){
		return y;
	}
	else if (index==2){
		return z;
	}
}

matrix33  &matrix33::operator =  (const matrix33 &m){
	x= m.x;
	y= m.y;
	z= m.z;
	
}
matrix33  &matrix33::operator +=  (const matrix33 &m){
	x+= m.x;
	y+= m.y;
	z+= m.z;
}

matrix33  &matrix33::operator -=  (const matrix33 &m){
	x-= m.x;
	y-= m.y;
	z-= m.z;
}
matrix33  &matrix33::operator *=  (float f){
	x=x*f;
	y=y*f;
	z=z*f;
}
matrix33  &matrix33::operator /=  (float f){
	x=x/f;
	y=y/f;
	z=z/f;
	
}
bool operator ==(const matrix33 &a, const matrix33 &b){
	if(a.x==b.x&&a.y==b.y&&a.z==b.z){
		return true;
	}
	else{
		return false;
	}	
}
bool operator !=(const matrix33 &a, const matrix33 &b){
	if(a.x!=b.x||a.y!=b.y||a.z!=b.z){
		return false;
	}
	else {
		return true;
	}
}

matrix33  operator - (const matrix33 &a){
	matrix33 ret;
	ret.x=-a.x;
	ret.y=-a.y;
	ret.z=-a.z;
	return ret;
}
matrix33  operator + (const matrix33 &a, const matrix33 &b){
	matrix33 ret;
	ret.x=a.x+b.x;
	ret.y=a.y+b.y;
	ret.z=a.z+b.z;
	return ret;
}
matrix33  operator - (const matrix33 &a, const matrix33 &b){
	matrix33 ret;
	ret.x=a.x-b.x;
	ret.y=a.y-b.y;
	ret.z=a.z-b.z;
	return ret;
}
matrix33  operator * (const matrix33 &a, const matrix33 &b){
	matrix33 ret;
	ret.x.x=a.x.x*b.x.x+a.y.x*b.x.y+a.z.x*b.x.z;//00
	ret.y.x=a.x.x*b.y.x+a.y.x*b.y.y+a.z.x*b.y.z;//10
	ret.z.x=a.x.x*b.z.x+a.y.x*b.z.y+a.z.x*b.z.z;//20
	ret.x.y=a.x.y*b.x.x+a.y.y*b.x.y+a.z.y*b.x.z;//01
	ret.y.y=a.x.y*b.y.x+a.y.y*b.y.y+a.z.y*b.y.z;//11
	ret.z.y=a.x.y*b.z.x+a.y.y*b.z.y+a.z.y*b.z.z;//21
	ret.x.z=a.x.z*b.x.x+a.y.z*b.x.y+a.z.z*b.x.z;//02
	ret.y.z=a.x.z*b.y.x+a.y.z*b.y.y+a.z.z*b.y.z;//12
	ret.z.z=a.x.z*b.z.x+a.y.z*b.z.y+a.z.z*b.z.z;//22
	return ret;
}
matrix33  operator * (const matrix33 &m, float f){
	matrix33 ret;
	ret.x=m.x*f;
	ret.y=m.y*f;
	ret.z=m.z*f;
	return ret;
}
matrix33  operator * (float f, const matrix33 &m){
	matrix33 ret;
	ret.x=f*m.x;
	ret.y=f*m.y;
	ret.z=f*m.z;
	return ret;
}
matrix33  operator / (const matrix33 &m, float f){
	matrix33 ret;
	ret.x=m.x/f;
	ret.y=m.y/f;
	ret.z=m.z/f;
	return ret;
}



void matrix33::set(vector3 AIn, vector3 BIn, vector3 CIn){
	x.x= AIn.x;
	x.y= AIn.y;
	x.z= AIn.z;
	y.x= BIn.x;
	y.y= BIn.y;
	y.z= BIn.z;
	z.x= CIn.x;
	z.y= CIn.y;
	z.z= CIn.z;
}
matrix33 matrix33::invert(){
	matrix33 ret;
	float aa,bb,cc,dd,ee,ff,gg,hh,ii;
	float a,b,c,d;
	a=x.x*(y.y*z.z-z.y*y.z);
	b=y.x*(x.y*z.z-x.z*z.y);
	c=z.x*(x.y*y.z-x.z*y.y);
	d= a-b+c;
	
	aa= (y.y*z.z-z.y*y.z)/d;//00
	bb=-(x.y*z.z-x.z*z.y)/d;//01
	cc= (x.y*y.z-x.z*y.y)/d;//02
	dd=-(y.x*z.z-y.z*z.x)/d;//10
	ee= (x.x*z.z-x.z*z.x)/d;//11
	ff=-(x.x*y.z-x.z*y.x)/d;//12
	gg= (y.x*z.y-y.y*z.x)/d;//20
	hh=-(x.x*z.y-x.y*z.x)/d;//21
	ii= (x.x*y.y-x.y*y.x)/d;//22
	ret.x.x=aa;
	ret.x.y=bb;
	ret.x.z=cc;
	ret.y.x=dd;
	ret.y.y=ee;
	ret.y.z=ff;
	ret.z.x=gg;
	ret.z.y=hh;
	ret.z.z=ii;
	return ret;
}
float matrix33::determinant(){
	float a,b,c,d;
	a=x.x*(y.y*z.z-z.y*y.z);
	b=y.x*(x.y*z.z-x.z*z.y);
	c=z.x*(x.y*y.z-x.z*y.y);
	d= a-b+c;
	return d;
}
matrix33 matrix33::identity(){
	
	x.x=1;
	x.y=0;
	x.z=0;
	y.x=0;
	y.y=1;
	y.z=0;
	z.x=0;
	z.y=0;
	z.z=1;
}
void matrix33::printMatrix()const{
	cout << x.x<<"  "<< y.x<<"  "<< z.x<<endl;
	cout << x.y<<"  "<< y.y<<"  "<< z.y<<endl;
	cout << x.z<<"  "<< y.z<<"  "<< z.z<<endl;
}
