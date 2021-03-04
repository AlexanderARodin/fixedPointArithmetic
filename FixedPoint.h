
#define FP_DIGITS 5


class FixedPoint{
    int _rawValue;

    public:
        FixedPoint(){
            _rawValue = 0;
        }
        FixedPoint(int value){
            (*this)=value;
        }
        FixedPoint(double value){
            (*this)=value;
        }

    friend FixedPoint operator-(FixedPoint& src){
        FixedPoint result=src;
        result._rawValue = -result._rawValue;
        return result;
    }
    
    FixedPoint& operator=(int value){
        if(value>=0){
            _rawValue = value<<FP_DIGITS;
        }else{
            *this = -value;
            _rawValue = -_rawValue;
        }
        return *this;
    }
    FixedPoint& operator=(double value){
        if(value>=0){
            _rawValue = value *(1<<FP_DIGITS);
        }else{
            *this = -value;
            _rawValue = -_rawValue;
        }
        return *this;
    }
    double getDouble(){
        return 1./(1<<FP_DIGITS)*_rawValue;
    }
    int getInt(){
        return _rawValue>>FP_DIGITS;
    }
 
    friend FixedPoint operator+(const FixedPoint& leftVal, const FixedPoint& rightVal){
        FixedPoint result = leftVal;
            result._rawValue += rightVal._rawValue;
        return result;
    }
    friend FixedPoint operator-(const FixedPoint& leftVal, const FixedPoint& rightVal){
        FixedPoint result = leftVal;
            result._rawValue -= rightVal._rawValue;
        return result;
    }
    friend FixedPoint operator*(const FixedPoint& leftVal, const FixedPoint& rightVal){
        long int _result=leftVal._rawValue;
            _result *= rightVal._rawValue;
        return (int)(_result>>(FP_DIGITS<<1));
    }
    friend FixedPoint operator/(const FixedPoint& leftVal, const FixedPoint& rightVal){
        long int _result=leftVal._rawValue;
            _result /= rightVal._rawValue;
        return (int)_result;
    }

    friend FixedPoint operator+(const FixedPoint& leftVal, int rightVal){
        FixedPoint rval = rightVal;
        return leftVal + rval;
    }
    friend FixedPoint operator-(const FixedPoint& leftVal, int rightVal){
        FixedPoint rval = rightVal;
        return leftVal - rval;
    }
    friend FixedPoint operator*(const FixedPoint& leftVal, int rightVal){
        FixedPoint rval = rightVal;
        return leftVal * rval;
    }
    friend FixedPoint operator/(const FixedPoint& leftVal, int rightVal){
        FixedPoint rval = rightVal;
        return leftVal / rval;
    }

    friend FixedPoint operator+(const FixedPoint& leftVal, double rightVal){
        FixedPoint rval = rightVal;
        return leftVal + rval;
    }
    friend FixedPoint operator-(const FixedPoint& leftVal, double rightVal){
        FixedPoint rval = rightVal;
        return leftVal - rval;
    }
    friend FixedPoint operator*(const FixedPoint& leftVal, double rightVal){
        FixedPoint rval = rightVal;
        return leftVal * rval;
    }
    friend FixedPoint operator/(const FixedPoint& leftVal, double rightVal){
        FixedPoint rval = rightVal;
        return leftVal / rval;
    }

    friend FixedPoint operator+(int leftVal, const FixedPoint& rightVal){
        FixedPoint lval = leftVal;
        return lval + rightVal;
    }
    friend FixedPoint operator-(int leftVal, const FixedPoint& rightVal){
        FixedPoint lval = leftVal;
        return lval - rightVal;
    }
    friend FixedPoint operator*(int leftVal, const FixedPoint& rightVal){
        FixedPoint lval = leftVal;
        return lval * rightVal;
    }
    friend FixedPoint operator/(int leftVal, const FixedPoint& rightVal){
        FixedPoint lval = leftVal;
        return lval / rightVal;
    }


    friend FixedPoint operator+(double leftVal, const FixedPoint& rightVal){
        FixedPoint lval = leftVal;
        return lval + rightVal;
    }
    friend FixedPoint operator-(double leftVal, const FixedPoint& rightVal){
        FixedPoint lval = leftVal;
        return lval - rightVal;
    }
    friend FixedPoint operator*(double leftVal, const FixedPoint& rightVal){
        FixedPoint lval = leftVal;
        return lval * rightVal;
    }
    friend FixedPoint operator/(double leftVal, const FixedPoint& rightVal){
        FixedPoint lval = leftVal;
        return lval / rightVal;
    }

    
};
