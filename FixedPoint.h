

class FixedPoint{
    int _rawValue;

    public:
        FixedPoint(){
            _rawValue = 0;
        }
        FixedPoint(int value){
            (*this)=value;
        }

    friend FixedPoint operator-(FixedPoint& src){
        FixedPoint result=src;
        result._rawValue = -result._rawValue;
        return result;
    }
    
    FixedPoint& operator=(int value){
        if(value>=0)_rawValue = value<<5;
        if(value<0){
            _rawValue = (-value)<<5;
            ??_rawValue = -_rawValue;
        }
        return *this;
    }
    //FixedPoint& operator=(double value){
    //    if(value>=0)_rawValue = value *32;
    //    if(value<0)_rawValue = -((int)(-value*32));
    //    return *this;
    //}

    friend FixedPoint operator+(FixedPoint& leftVal, FixedPoint& rightVal ){
        FixedPoint result = leftVal;
            result._rawValue += rightVal._rawValue;
        return result;
    }


    //friend FixedPoint operator*(FixedPoint& leftVal, FixedPoint& rightVal ){
    //    int _result=leftVal._rawValue;// * rightVal._rawValue>>5;
    //    return _result>>5;
    //}

    
String toTxt(){
        String res;
            for(int i=0;i<16;i++)
                res = ((1<<i & _rawValue) ? 1:0) + res;
            res = "0b"+res;
        int RR = _rawValue>>5;
        int rr = (_rawValue&0b11111)<<5;
        return res+'\t'+String(RR,DEC)+'.'+String(rr,DEC);
    }
};

void msgln(const String& str);
void tst(){
    FixedPoint aa=1;
    FixedPoint bb=1;
        msgln( aa.toTxt() );
        aa=0;
        msgln( aa.toTxt() );
        aa=-1;
        msgln( aa.toTxt() );
        
    msgln("\n-1");
        aa=1;
        aa = (-aa);
        msgln( (aa).toTxt() );
        
    //msgln("\n1.5");
        aa=1.5;
        //msgln( (aa).toTxt() );
    //msgln("\n-1.5");
        aa=-1.5;
        //msgln( (aa).toTxt() );
        
    //msgln("\n1+(-1)");
    aa=1.5;
    bb=-1;
    //msgln( (aa+bb).toTxt() );
        
    //msgln("\n1*1");
    aa=1;
    bb=1;
    //msgln( (aa*bb).toTxt() );
}
