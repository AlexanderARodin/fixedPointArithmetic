#include <raaDBG.h>

#include <raaFixedPoint.h>
#include <raaLCD12864J.h>




BufferLCD video;


void setup(){
	delay(200);
	Serial.begin(115200);
	msg("\n\n\n\n#################\n"
				"# >> Started << #\n"
				"#################\n\n");
	video.initLCD(A6,A7,13,12,0,11,10,9,8,7,6,5,4);
	//fillBackground();

	//tst0();
	//tst1();
	//tst2();
	//tst3();
	//tst4();
	//tst5();
	//tst6();
	//tstSpec();
	//tstSIN();
	//tstSinCos();
	
	//while(true)delay(99999);
}

void loop(){
	
/*	for(FixedPoint x = -1; x<1;x.doIncrement()){
		video.setPixel(INVERT_PIXEL, x*64+64, 31+32*fpSin(x) );
		video.setPixel(INVERT_PIXEL, x*64+64, 31+32*fpCos(x) );
		video.sendToLCD();
		//msg( x.toTxt() );
		//msg( tabStr+ fpSin(x).toDouble() );
		//msgln( "" );
	//delay(5);
	}
*/	
	
	static FixedPoint looper=0;


	FixedPoint R = 30;
		FixedPoint sn1 = fpSin(looper);
		FixedPoint cs1 = fpCos(looper);
		FixedPoint sn3 = fpSin(looper-0.25);
		FixedPoint cs3 = fpCos(looper-0.25);
		FixedPoint sn2 = fpSin(looper+0.25);
		FixedPoint cs2 = fpCos(looper+0.25);
		video.setLine(INVERT_PIXEL, 64,32,R*sn1 + 64,R*cs1 + 32 );
		video.setRect(INVERT_PIXEL, 	R*sn2 + 64-4,R*cs2 + 32-8,
										R*sn2 + 64+4,R*cs2 + 32+8 );
		video.setEllipse(INVERT_PIXEL,  R*sn3 + 64-8,R*cs3 + 32-4,
										R*sn3 + 64+8,R*cs3 + 32+4 );
	video.sendToLCD();
	
	//delay(5);

		//video.setLine(INVERT_PIXEL, 64,32,R*sn1 + 64,R*cs1 + 32 );
		video.setRect(INVERT_PIXEL, 	R*sn2 + 64-4,R*cs2 + 32-8,
										R*sn2 + 64+4,R*cs2 + 32+8 );
		video.setEllipse(INVERT_PIXEL,  R*sn3 + 64-8,R*cs3 + 32-4,
										R*sn3 + 64+8,R*cs3 + 32+4 );

	//dbg(String((int)looper));
 
	looper.doIncrement();
}

void fillBackground(){
	for(int X=0;X<128;X++)
	  for(int Y=0;Y<64;Y++){
		video.setPixel(random(255)<239?SET_PIXEL:CLEAR_PIXEL, X,Y);
	  }
	video.setRect(INVERT_PIXEL,	3, 3, 124, 60 );
	video.sendToLCD();
}

/*
String FixedPoint::toTxt(){
		String res;
			for(int i=0;i<16;i++)
				res = ((1<<i & _rawValue) ? 1:0) + res;
			res = "0b"+res;
		return res+"  "+String( 1./(1<<FP_DIGITS)*_rawValue,4);//String(RR,DEC)+'.'+String(rr,DEC);
	}
void tst0(){
	msgln("\ninit by INT and unitary minus");	
	FixedPoint aa=1;
	FixedPoint bb=1;
		for(int i=-3;i<=3;i++){
			aa=i;
			msg( aa.toTxt() +'\n' );
			bb = -aa;
			msgln( bb.toTxt() );
			msgln( String(aa.toDouble()) + '\t' + (int)aa );
		}
}
void tst1(){
	msgln("\ninit by DBL and unitary minus");	
	FixedPoint aa=1;
	FixedPoint bb=1;
		for(double d=-1.5;d<=1.5;d+=0.5){
			aa=d;
			msg( aa.toTxt() +'\n' );
			bb = -aa;
			msgln( bb.toTxt() );
			msgln( String(aa.toDouble()) + '\t' + (int)aa );
		}
}
void tst2(){
	msgln("\nbase operations");	
	msg( "aa\tbb\taa+bb\taa-bb\taa*bb\taa/bb\n" );
	FixedPoint aa=1;
	FixedPoint bb=1;
		for(double da=-1.;da<=1.;da+=0.5){
			for(double db=-1.;db<=1.;db+=0.5){
				aa=da;
				bb=db;
				msg(	emptyStr + aa.toDouble() );
				msg(	  tabStr + bb.toDouble() );
				msg( tabStr + (aa+bb).toDouble() );
				msg( tabStr + (aa-bb).toDouble() );
				msg( tabStr + (aa*bb).toDouble() );
				msg( tabStr + (aa/bb).toDouble() );
				msgln("");
			}
		}
}
void tst3(){
	msgln("\nbase operations WITH INT");	
	msg( "aa\tib\taa+ib\taa-ib\taa*ib\taa/ib\n" );
	FixedPoint aa=1;
		for(double da=-1.;da<=1.;da+=0.5){
			for(int ib=-2;ib<=2.;ib++){
				aa=da;
				msg(	emptyStr + aa.toDouble() );
				msg(	  tabStr + ib );
				msg( tabStr + (aa+ib).toDouble() );
				msg( tabStr + (aa-ib).toDouble() );
				msg( tabStr + (aa*ib).toDouble() );
				msg( tabStr + (aa/ib).toDouble() );
				msgln("");
			}
		}
}
void tst4(){
	msgln("\nbase operations WITH DOUBLE");	
	msg( "aa\tdb\taa+db\taa-db\taa*db\taa/db\n" );
	FixedPoint aa=1;
		for(double da=-1.;da<=1.;da+=0.5){
			for(double db=-1.;db<=1.;db+=0.5){
				aa=da;
				msg(	emptyStr + aa.toDouble() );
				msg(	  tabStr + db );
				msg( tabStr + (aa+db).toDouble() );
				msg( tabStr + (aa-db).toDouble() );
				msg( tabStr + (aa*db).toDouble() );
				msg( tabStr + (aa/db).toDouble() );
				msgln("");
			}
		}
}
void tst5(){
	msgln("\nbase operations INT WITH");	
	msg( "ia\tbb\tia+bb\tia-bb\tia*bb\tia/bb\n" );
	FixedPoint bb=1;
		for(double ia=-2;ia<=2;ia++){
			for(double db=-1.;db<=1.;db+=0.5){
				bb=db;
				msg(	emptyStr + ia );
				msg(	  tabStr + bb.toDouble() );
				msg( tabStr + (ia+bb).toDouble() );
				msg( tabStr + (ia-bb).toDouble() );
				msg( tabStr + (ia*bb).toDouble() );
				msg( tabStr + (ia/bb).toDouble() );
				msgln("");
			}
		}
}
void tst6(){
	msgln("\nbase operations DOUBLE WITH");	
	msg( "da\tbb\tda+bb\tda-bb\tda*bb\tda/bb\n" );
	FixedPoint bb=1;
		for(double da=-1.;da<=1.;da+=0.5){
			for(double db=-1.;db<=1.;db+=0.5){
				bb=db;
				msg(	emptyStr + da );
				msg(	  tabStr + bb.toDouble() );
				msg( tabStr + (da+bb).toDouble() );
				msg( tabStr + (da-bb).toDouble() );
				msg( tabStr + (da*bb).toDouble() );
				msg( tabStr + (da/bb).toDouble() );
				msgln("");
			}
		}
}

void tstSpec(){
	msgln("\nSpecTest");	
	FixedPoint aa=1;
	FixedPoint bb=1;
	FixedPoint cc=1;
		for(int i=1;i<=128;i++){
			for(int j=1;j<=128;j++){
				aa=i;
				bb=j;
				cc = aa / bb;
				double d = (1.-1+i/j) - ((int)cc);
				if(d <-1000 || d>1000)continue;
				msg( emptyStr+ aa.toDouble() +'\t' +bb.toDouble()  );
				if(d!=0){
					msg( tabStr+ cc.toDouble() +lnStr );
					delay(1000);
				}else{
					msg( tabStr+ "Ok-k-k!!" +lnStr );
				}
			}
		}
}

void tstSIN(){
	msgln("\nSIN");	
	FixedPoint angl=1;
		for(int i=-32;i<=32;i++){
			angl=i/32.;
			msg( angl.toTxt() );
			msg( tabStr + fpSin(angl).toDouble() );
			msgln("");
		}
}
void tstSinCos(){
	msgln("\nSinCos");	
	FixedPoint angl=1;
		for(int i=-32;i<=32;i++){
			angl=i/32.;
			msg( angl.toTxt() );
			msg( tabStr + fpSin(angl).toDouble() );
			msg( tabStr + fpCos(angl).toDouble() );
			msg( tabStr + (fpCos(angl)*fpCos(angl)+fpSin(angl)*fpSin(angl)).toDouble() );
			msg( tabStr + (fpCos(angl)*fpCos(angl)+fpSin(angl)*fpSin(angl)).toTxt() );
			msgln("");
		}
}
*/
