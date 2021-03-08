
#include <raaFixedPoint.h>
//	############################################################
//	############################################################
//	############################################################
//	############################################################



FixedPoint::FixedPoint(){ _rawValue = 0; }
FixedPoint::FixedPoint(int value){ (*this)=value; }
FixedPoint::FixedPoint(double value){ (*this)=value; }

FixedPoint operator-(FixedPoint& src){
	FixedPoint result=src;
	result._rawValue = -result._rawValue;
	return result;
}

FixedPoint& FixedPoint::operator=(int value){
	if(value>=0){
		_rawValue = value<<FP_DIGITS;
	}else{
		*this = -value;
		_rawValue = -_rawValue;
	}
	return *this;
}
FixedPoint& FixedPoint::operator=(double value){
	if(value>=0){
		_rawValue = value *(1<<FP_DIGITS);
	}else{
		*this = -value;
		_rawValue = -_rawValue;
	}
	return *this;
}
double FixedPoint::toDouble(){
	return 1./(1<<FP_DIGITS)*_rawValue;
}
FixedPoint::operator int(){
	return _rawValue>>FP_DIGITS;
}

void FixedPoint::doIncrement(){
	_rawValue++;
}
void FixedPoint::doDecrement(){
	_rawValue--;
}

//	############################################################

FixedPoint operator+(const FixedPoint& leftVal, const FixedPoint& rightVal){
	FixedPoint result = leftVal;
	result._rawValue += rightVal._rawValue;
	return result;
}
FixedPoint operator-(const FixedPoint& leftVal, const FixedPoint& rightVal){
	FixedPoint result = leftVal;
	result._rawValue -= rightVal._rawValue;
	return result;
}
FixedPoint operator*(const FixedPoint& leftVal, const FixedPoint& rightVal){
	long int _longInt=leftVal._rawValue;
	_longInt *= rightVal._rawValue;
	FixedPoint result;
	result._rawValue = _longInt>>FP_DIGITS;
	return result;
}
FixedPoint operator/(const FixedPoint& leftVal, const FixedPoint& rightVal){
	long int _longInt=((long int)leftVal._rawValue)<<FP_DIGITS;
	_longInt /= rightVal._rawValue;
	FixedPoint result;
	result._rawValue = _longInt;
	return result;
}

//	############################################################

FixedPoint operator+(const FixedPoint& leftVal, int rightVal){
	FixedPoint rval = rightVal;
	return leftVal + rval;
}
FixedPoint operator-(const FixedPoint& leftVal, int rightVal){
	FixedPoint rval = rightVal;
	return leftVal - rval;
}
FixedPoint operator*(const FixedPoint& leftVal, int rightVal){
	FixedPoint rval = rightVal;
	return leftVal * rval;
}
FixedPoint operator/(const FixedPoint& leftVal, int rightVal){
	FixedPoint rval = rightVal;
	return leftVal / rval;
}

//	############################################################

FixedPoint operator+(const FixedPoint& leftVal, double rightVal){
	FixedPoint rval = rightVal;
	return leftVal + rval;
}
FixedPoint operator-(const FixedPoint& leftVal, double rightVal){
	FixedPoint rval = rightVal;
	return leftVal - rval;
}
FixedPoint operator*(const FixedPoint& leftVal, double rightVal){
	FixedPoint rval = rightVal;
	return leftVal * rval;
}
FixedPoint operator/(const FixedPoint& leftVal, double rightVal){
	FixedPoint rval = rightVal;
	return leftVal / rval;
}

//	############################################################

FixedPoint operator+(int leftVal, const FixedPoint& rightVal){
	FixedPoint lval = leftVal;
	return lval + rightVal;
}
FixedPoint operator-(int leftVal, const FixedPoint& rightVal){
	FixedPoint lval = leftVal;
	return lval - rightVal;
}
FixedPoint operator*(int leftVal, const FixedPoint& rightVal){
	FixedPoint lval = leftVal;
	return lval * rightVal;
}
FixedPoint operator/(int leftVal, const FixedPoint& rightVal){
	FixedPoint lval = leftVal;
	return lval / rightVal;
}

//	############################################################

FixedPoint operator+(double leftVal, const FixedPoint& rightVal){
	FixedPoint lval = leftVal;
	return lval + rightVal;
}
FixedPoint operator-(double leftVal, const FixedPoint& rightVal){
	FixedPoint lval = leftVal;
	return lval - rightVal;
}
FixedPoint operator*(double leftVal, const FixedPoint& rightVal){
	FixedPoint lval = leftVal;
	return lval * rightVal;
}
FixedPoint operator/(double leftVal, const FixedPoint& rightVal){
	FixedPoint lval = leftVal;
	return lval / rightVal;
}


//	############################################################
//	############################################################



struct {int fpSin; int fpCos;} trigonomTable[32]={
	{  0, 32},
	{  8, 31},
	{ 14, 29},
	{ 19, 26},
	{ 23, 23},
	{ 26, 19},
	{ 29, 14},
	{ 31,  8},
	{ 32,  0},
	{ 31, -8},
	{ 29,-14},
	{ 26,-19},
	{ 23,-23},
	{ 19,-26},
	{ 14,-29},
	{  8,-31},
	{  0,-32},
	{ -8,-31},
	{-14,-29},
	{-19,-26},
	{-23,-23},
	{-26,-19},
	{-29,-14},
	{-31, -8},
	{-32,  0},
	{-31,  8},
	{-29, 14},
	{-26, 19},
	{-23, 23},
	{-19, 26},
	{-14, 29},
	{ -8, 31}
};


FixedPoint fpSin(FixedPoint value){
	int index = value._rawValue & ((1<<FP_DIGITS)-1);
	return FixedPoint(trigonomTable[index].fpSin)/32;
}
FixedPoint fpCos(FixedPoint value){
	int index = value._rawValue & ((1<<FP_DIGITS)-1);
	return FixedPoint(trigonomTable[index].fpCos)/32;
}
