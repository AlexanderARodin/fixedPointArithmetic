#ifndef RAAFIXEDPOINT_H
#define RAAFIXEDPOINT_H

#include <Arduino.h>
//	############################################################
//	############################################################
//	############################################################
//	############################################################


#define FP_DIGITS 5


class FixedPoint{
	int _rawValue;
	
public:
	FixedPoint();
	FixedPoint(int value);
	FixedPoint(double value);
	
	friend FixedPoint operator-(FixedPoint& src);
	
	FixedPoint& operator=(int value);
	FixedPoint& operator=(double value);
	double toDouble();
	operator int();
	void doIncrement();
	void doDecrement();
	
	friend FixedPoint operator+(const FixedPoint& leftVal, const FixedPoint& rightVal);
	friend FixedPoint operator-(const FixedPoint& leftVal, const FixedPoint& rightVal);
	friend FixedPoint operator*(const FixedPoint& leftVal, const FixedPoint& rightVal);
	friend FixedPoint operator/(const FixedPoint& leftVal, const FixedPoint& rightVal);
	
	friend FixedPoint operator+(const FixedPoint& leftVal, int rightVal);
	friend FixedPoint operator-(const FixedPoint& leftVal, int rightVal);
	friend FixedPoint operator*(const FixedPoint& leftVal, int rightVal);
	friend FixedPoint operator/(const FixedPoint& leftVal, int rightVal);
	
	friend FixedPoint operator+(const FixedPoint& leftVal, double rightVal);
	friend FixedPoint operator-(const FixedPoint& leftVal, double rightVal);
	friend FixedPoint operator*(const FixedPoint& leftVal, double rightVal);
	friend FixedPoint operator/(const FixedPoint& leftVal, double rightVal);
	
	friend FixedPoint operator+(int leftVal, const FixedPoint& rightVal);
	friend FixedPoint operator-(int leftVal, const FixedPoint& rightVal);
	friend FixedPoint operator*(int leftVal, const FixedPoint& rightVal);
	friend FixedPoint operator/(int leftVal, const FixedPoint& rightVal);
	
	friend FixedPoint operator+(double leftVal, const FixedPoint& rightVal);
	friend FixedPoint operator-(double leftVal, const FixedPoint& rightVal);
	friend FixedPoint operator*(double leftVal, const FixedPoint& rightVal);
	friend FixedPoint operator/(double leftVal, const FixedPoint& rightVal);
	
	friend FixedPoint fpSin(FixedPoint value);
	friend FixedPoint fpCos(FixedPoint value);
	friend String toTxt();
};



FixedPoint fpSin(FixedPoint value);
FixedPoint fpCos(FixedPoint value);

//	############################################################
//	############################################################
//	############################################################
//	############################################################
#endif
