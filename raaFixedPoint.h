
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
    double toDouble(){
        return 1./(1<<FP_DIGITS)*_rawValue;
    }
    operator int(){
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
    
    friend FixedPoint fpSin(FixedPoint value);
    friend FixedPoint fpCos(FixedPoint value);
    String toTxt();
};



struct {int fpSin; int fpCos;} trigonomTable[]={
                                    {0,32},
                                    {6,31},
                                    {12,29},
                                    {17,26},
                                    {22,22},
                                    {26,17},
                                    {29,12},
                                    {31,6},
                                    {32,0},
                                    {31,-7},
                                    {29,-13},
                                    {26,-18},
                                    {22,-23},
                                    {17,-27},
                                    {12,-30},
                                    {6,-32},
                                    {0,-32},
                                    {-7,-32},
                                    {-13,-30},
                                    {-18,-27},
                                    {-23,-23},
                                    {-27,-18},
                                    {-30,-13},
                                    {-32,-7},
                                    {-32,-1},
                                    {-32,6},
                                    {-30,12},
                                    {-27,17},
                                    {-23,22},
                                    {-18,26},
                                    {-13,29},
                                    {-7,31}
                                };

FixedPoint fpSin(FixedPoint value){
        int index = value._rawValue;// & ((1<<FP_DIGITS)-1);
    return value;index*32;
    }
FixedPoint fpCos(FixedPoint value);
