#include<reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit dula=P2^6;
sbit wela=P2^7;
sbit adwr=P3^6;
sbit adrd=P3^7;                             //IO口定义
uchar code table[]={                       	//数码管编码
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,			
0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,
0x79,0x71};
uchar code table1[]={
0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,			
0x87,0xff,0xef
};
double aa=5000.0/256;	 //加点0，aa结果有小数，可以提高精度，不加点0结果小数部分全为0

void delay(uint xms)                       //延时程序
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}
void display(uchar qian,uchar bai,uchar shi,uchar ge)			//显示程序
{  
	dula=1;
    P0=table1[qian];		//显示千位
    dula=0;
	P0=0xff;
    wela=1;
	P0=0x7e;
    wela=0;
    delay(5);

	dula=1;
    P0=table[bai];		//显示百位
    dula=0;
	P0=0xff;
    wela=1;
	P0=0x7d;
    wela=0;
    delay(5);

    dula=1;				//显示十位
    P0=table[shi];		
    dula=0;
	P0=0xff;
    wela=1;
	P0=0x7b;
    wela=0;
    delay(5);

    dula=1;				//显示个位
    P0=table[ge];		
    dula=0;
	P0=0xff;
    wela=1;
    P0=0x77;
    wela=0;
    delay(5);  						
  

}
void main()		//	主程序
{

  	uint a,A1,A2,A3,A4,adval,ww;
	wela=1;
	P0=0x7f;
	wela=0;    
    while(1)
  	{
		adwr=1;			
	    _nop_();
	    adwr=0;
		_nop_();
	    adwr=1;         
        for(a=10;a>0;a--)        	//需要注意的是ADC0804在写和读之间的时间间隔要足够长否则无法读出数据
    	{                           //这里把显示部分放这里的原因也是为了增加写读之间的时间间隔                                                                                                                                                                                                                           
        	display(A1,A2,A3,A4);
    	}							//送去显示各位。
     	P1=0xff;                    	//读取P1口之前先给其写全1
		adrd=1;
		_nop_();
		adrd=0;
		_nop_();
		ww=P1;
		adval=ww*aa;
		adrd=1;  
	    A1=adval/1000;		//分出百，十，和个位
	    A2=adval%1000/100;
	    A3=adval%1000%100/10;
        A4=adval%10;
   }
}