
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

/*
void msg(const String& str);
void msgln(const String& str);

String toTxt(){
        String res;
            for(int i=0;i<16;i++)
                res = ((1<<i & _rawValue) ? 1:0) + res;
            res = "0b"+res;
        return res+'\t'+String( 1./(1<<FP_DIGITS)*_rawValue,4);//String(RR,DEC)+'.'+String(rr,DEC);
    }

void tst(){
    FixedPoint aa=1;
    FixedPoint bb=1;
        for(int i=-3;i<=3;i++){
            aa=i;
            msgln( aa.toTxt() );
            bb = aa;
            msgln( (aa+bb).toTxt() );
        }
        msgln("\n0-1");    
        aa=0;
        bb=-1;
        msgln( (aa+bb).toTxt() );
        
    msgln("\n1+(-1)");
    aa=1;
    bb=-1;
    msgln( (aa+bb).toTxt() );
    msgln( (aa+(-1)).toTxt() );
    msgln( (1+bb).toTxt() );
    msgln( (aa+(-1.)).toTxt() );
    msgln( (1.+bb).toTxt() );
        
    msgln("\n1-1");
    aa=1;
    bb=1;
    msgln( (aa-bb).toTxt() );
    msgln( (aa-1).toTxt() );
    msgln( (1-bb).toTxt() );
    msgln( (aa-1.).toTxt() );
    msgln( (1.-bb).toTxt() );
        
    msgln("\n-1");
        aa=1;
        aa = (-aa);
        msgln( (aa).toTxt() );


        msgln("\n0..1");    
        for(int i=0;i<=8;i++){
            aa=0.125*i;
            msg( String(i)+'\n' );
            msgln( aa.toTxt() );
            bb=1-0.125*i+2;
            msgln( bb.toTxt() );
            msgln( (aa+bb).toTxt() );
        }
        
    msgln("\n2.5");
        aa=2.5;
        msgln( (aa).toTxt() );
    msgln("\n-2.5");
        aa=-2.5;
        msgln( (aa).toTxt() );
        
    msgln("\n-40*3");
    aa=-40;
    bb=3;
    msgln( (aa*bb).toTxt() );
    msgln( (aa*3.).toTxt() );
    msgln( (aa*3).toTxt() );
    msgln( (-40*bb).toTxt() );
    msgln( (-40.*bb).toTxt() );

    msgln("\n-256/8");
    aa=-256;
    bb=8;
    msgln( (aa/bb).toTxt() );
    msgln( (aa/8).toTxt() );
    msgln( (aa/8.).toTxt() );
    msgln( (-256/bb).toTxt() );
    msgln( (-256./bb).toTxt() );

    msgln( "" );
    msgln( String(aa.getInt()) );
    msgln( String(aa.getDouble()) );


}*/
