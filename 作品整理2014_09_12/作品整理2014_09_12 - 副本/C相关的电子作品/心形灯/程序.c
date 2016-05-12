#include<reg52.h>
#include<intrins.h>
unsigned int x,y;

void delayms(unsigned int z)

{unsigned int i,j;

for(i=z;i>0;i--)

for(j=110;j>0;j--);}

void Offall() //开启所有灯	                                  
{P0=0xff;P1=0x00;P2=0x00;P3=0x00;}

void Onall()//关闭所有灯			                          
{P0=0x00;P1=0xff;P2=0xff;P3=0xff;}
void ls()//等时流水灯										  
{
P0=0xff;
P0=0xfe;delayms(50); 
P0=0xfd; delayms(50);
P0=0xfb; delayms(50) ;
P0=0xf7; delayms(50)  ;
P0=0xef; delayms(50) ;
P0=0xdf;delayms(50);
P0=0xbf;delayms(50) ;
P0=0x7f;delayms(50);P0=0xff; 
P2=0x00;					
P2=0x80;delayms(50)  ;
P2=0x40; delayms(50);
P2=0x20; delayms(50) ;
P2=0x10; delayms(50)  ;
P2=0x08; delayms(50) ;
P2=0x04;delayms(50);
P2=0x02;delayms(50) ;
P2=0x01;delayms(50);P2=0x00;
P3=0x00;
P3=0x80;delayms(50)  ;
P3=0x40; delayms(50);
P3=0x20; delayms(50) ;
P3=0x10; delayms(50)  ;
P3=0x08; delayms(50) ;
P3=0x04;delayms(50);
P3=0x02;delayms(50) ;
P3=0x01;delayms(50);P3=0x00;
P1=0x00;
P1=0x80;delayms(50)  ;
P1=0x40; delayms(50);
P1=0x20; delayms(50) ;
P1=0x10; delayms(50)  ;
P1=0x08; delayms(50) ;
P1=0x04;delayms(50);
P1=0x02;delayms(50) ;
P1=0x01;delayms(50);P1=0x00;
P0=0xfe;delayms(50);P0=0xff;
}
void fxls()//反向等时流水灯									 
{
P0=0xff;
P0=0xfe;delayms(50);P0=0xff;
P1=0x00;
P1=0x01;delayms(50);
P1=0x02;delayms(50);
P1=0x04;delayms(50);
P1=0x08;delayms(50);
P1=0x10;delayms(50);
P1=0x20;delayms(50);
P1=0x40;delayms(50);
P1=0x80;delayms(50);P1=0x00;
P3=0x00;
P3=0x01;delayms(50);
P3=0x02;delayms(50);
P3=0x04;delayms(50);
P3=0x08;delayms(50);
P3=0x10;delayms(50);
P3=0x20;delayms(50);
P3=0x40;delayms(50);
P3=0x80;delayms(50);P3=0x00;
P2=0x00;
P2=0x01;delayms(50);
P2=0x02;delayms(50);
P2=0x04;delayms(50);
P2=0x08;delayms(50);
P2=0x10;delayms(50);
P2=0x20;delayms(50);
P2=0x40;delayms(50);
P2=0x80;delayms(50);P2=0x00;
P0=0xff;
P0=0x7f;delayms(50);
P0=0xbf;delayms(50);
P0=0xdf;delayms(50);
P0=0xef;delayms(50);
P0=0xf7;delayms(50);
P0=0xfb;delayms(50);
P0=0xfd;delayms(50);
P0=0xfe;delayms(50);P0=0xff;}
void bsb()//半双边流水 由上至下								  
{
Offall();
P0=0xfe;delayms(50);
P0=0xfd;P1=0x01;delayms(50);
P0=0xfb;P1=0x02;delayms(50);
P0=0xf7;P1=0x04;delayms(50);
P0=0xef;P1=0x08;delayms(50);
P0=0xdf;P1=0x10;delayms(50);
P0=0xbf;P1=0x20;delayms(50);
P0=0x7f;P1=0x40;delayms(50);P0=0xff;
P2=0x80;P1=0x80;delayms(50);P1=0x00;
P2=0x40;P3=0x01;delayms(50);
P2=0x20;P3=0x02;delayms(50);
P2=0x10;P3=0x04;delayms(50);
P2=0x08;P3=0x08;delayms(50);
P2=0x04;P3=0x10;delayms(50);
P2=0x02;P3=0x20;delayms(50);
P2=0x01;P3=0x40;delayms(50);Offall();
P3=0x80;delayms(50);Offall();
}
void fbsb()	   //半双边流水 由下至上						  
{
Offall();
P3=0x80;delayms(50);
P2=0x01;P3=0x40;delayms(50);
P2=0x02;P3=0x20;delayms(50);
P2=0x04;P3=0x10;delayms(50);
P2=0x08;P3=0x08;delayms(50);
P2=0x10;P3=0x04;delayms(50);
P2=0x20;P3=0x02;delayms(50);
P2=0x40;P3=0x01;delayms(50);Offall();
P2=0x80;P1=80;delayms(50);Offall();
P0=0x7f;P1=0x40;delayms(50);
P0=0xbf;P1=0x20;delayms(50);
P0=0xdf;P1=0x10;delayms(50);
P0=0xef;P1=0x08;delayms(50);
P0=0xf7;P1=0x04;delayms(50);
P0=0xfb;P1=0x02;delayms(50);
P0=0xfd;P1=0x01;delayms(50);Offall();
P0=0xfe;Offall();
}
ss(y)//闪烁（y为闪烁间隔时间）										      
{
Offall();delayms(y);
Onall();delayms(y);
}
void zxsz()//正向生长									  {
{Offall();
P0=0xfe;delayms(50);
P0=0xfc;delayms(50);
P0=0xf8;delayms(50);
P0=0xf0;delayms(50);
P0=0xe0;delayms(50);
P0=0xc0;delayms(50);
P0=0x80;delayms(50);
P0=0x00;delayms(50);
P2=0x80;delayms(50);
P2=0xc0;delayms(50);
P2=0xe0;delayms(50);
P2=0xf0;delayms(50);
P2=0xf8;delayms(50);
P2=0xfc;delayms(50);
P2=0xfe;delayms(50);
P2=0xff;delayms(50);
P3=0x80;delayms(50);
P3=0xc0;delayms(50);
P3=0xe0;delayms(50);
P3=0xf0;delayms(50);
P3=0xf8;delayms(50);
P3=0xfc;delayms(50);
P3=0xfe;delayms(50);
P3=0xff;delayms(50);
P1=0x80;delayms(50);
P1=0xc0;delayms(50);
P1=0xe0;delayms(50);
P1=0xf0;delayms(50);
P1=0xf8;delayms(50);
P1=0xfc;delayms(50);
P1=0xfe;delayms(50);
P1=0xff;delayms(50);
}
void fxsz()		//反向生长									  {
{Offall();
P0=0xfe;delayms(50);
P1=0x01;delayms(50);
P1=0x03;delayms(50);
P1=0x07;delayms(50);
P1=0x0f;delayms(50);
P1=0x1f;delayms(50);
P1=0x3f;delayms(50);
P1=0x7f;delayms(50);
P1=0xff;delayms(50);
P3=0x01;delayms(50);
P3=0x03;delayms(50);
P3=0x07;delayms(50);
P3=0x0f;delayms(50);
P3=0x1f;delayms(50);
P3=0x3f;delayms(50);
P3=0x7f;delayms(50);
P3=0xff;delayms(50);
P2=0x01;delayms(50);
P2=0x03;delayms(50);
P2=0x07;delayms(50);
P2=0x0f;delayms(50);
P2=0x1f;delayms(50);
P2=0x3f;delayms(50);
P2=0x7f;delayms(50);
P2=0xff;delayms(50);
P0=0x7e;delayms(50);
P0=0x3e;delayms(50);
P0=0x1e;delayms(50);
P0=0x0e;delayms(50);
P0=0x06;delayms(50);
P0=0x02;delayms(50);
P0=0x00;delayms(50);
}
void zxsw()		//正向死亡									  
{
Onall();
P0=0x02;delayms(50);
P0=0x06;delayms(50);
P0=0x0e;delayms(50);
P0=0x0f;delayms(50);
P0=0x1e;delayms(50);
P0=0x3e;delayms(50);
P0=0x7e;delayms(50);
P0=0xfe;delayms(50);
P2=0x7f;delayms(50);
P2=0x3f;delayms(50);
P2=0x1f;delayms(50);
P2=0x0f;delayms(50);
P2=0x07;delayms(50);
P2=0x03;delayms(50);
P2=0x01;delayms(50);
P2=0x00;delayms(50);
P3=0x7f;delayms(50);
P3=0x3f;delayms(50);
P3=0x1f;delayms(50);
P3=0x0f;delayms(50);
P3=0x07;delayms(50);
P3=0x03;delayms(50);
P3=0x01;delayms(50);
P3=0x00;delayms(50);
P1=0x7f;delayms(50);
P1=0x3f;delayms(50);
P1=0x1f;delayms(50);
P1=0x0f;delayms(50);
P1=0x07;delayms(50);
P1=0x03;delayms(50);
P1=0x01;delayms(50);
P1=0x00;delayms(50);
P0=0xff;delayms(50);
}
void fxsw()			  //反向死亡							 
{
Onall();
P1=0xfe;delayms(50);
P1=0xfc;delayms(50);
P1=0xf8;delayms(50);
P1=0xf0;delayms(50);
P1=0xe0;delayms(50);						 
P1=0xc0;delayms(50);
P1=0x80;delayms(50);
P1=0x00;delayms(50);
P3=0xfe;delayms(50);
P3=0xfc;delayms(50);
P3=0xf8;delayms(50);
P3=0xf0;delayms(50);
P3=0xe0;delayms(50);
P3=0xc0;delayms(50);
P3=0x80;delayms(50);
P3=0x00;delayms(50);
P2=0xfe;delayms(50);
P2=0xfc;delayms(50);
P2=0xf8;delayms(50);
P2=0xf0;delayms(50);
P2=0xe0;delayms(50);
P2=0xc0;delayms(50);
P2=0x80;delayms(50);
P2=0x00;delayms(50);
P0=0x80;delayms(50);
P0=0xc0;delayms(50);
P0=0xe0;delayms(50);
P0=0xf0;delayms(50);
P0=0xf8;delayms(50);
P0=0xfc;delayms(50);
P0=0xfe;delayms(50);
P0=0xff;delayms(50);
}
void c(x)	//间隔闪烁x为闪烁间隔时间										   
{
Offall();
P0=0x55;P2=0x55;P3=0x55;P1=0x55;delayms(x);
P0=0xaa;P2=0xaa;P3=0xaa;P1=0xaa;delayms(x);
}
void bbs()//半边交替闪										  
{

Offall();P0=0x00;P2=0xff;P3=0x80;delayms(200);Offall();P0=0xfe;P1=0xff;P3=0xff;delayms(200);
}
void sxs()//上下交替闪
{
Offall();P1=0xff;P0=0x00;P2=0x80;delayms(200);Offall();P2=0x7f;P3=0xff;delayms(200);
}
void cx()	//出现一点点
{
Offall();delayms(1000);
P0=0xff;P2=0x00;P1=0x40;P3=0x00;delayms(1000);
P0=0xdf;P2=0x40;P1=0x40;P3=0x00;delayms(1000);
P0=0xdb;P2=0x42;P1=0x40;P3=0x04;delayms(1000);
P0=0x59;P2=0x5a;P1=0x52;P3=0x65;delayms(1000);
P0=0x11;P2=0xdf;P1=0xdb;P3=0xef; delayms(1000);
P0=0x00;P2=0xff;P1=0xff;P3=0xff;delayms(1000);
}
void df()		  //单飞
{
P0=0xfe;delayms(50);
P0=0xfc;delayms(50);
P0=0xf8;delayms(50);
P0=0xf0;delayms(50);
P0=0xe0;delayms(50);
P0=0xc0;delayms(50);
P0=0x80;delayms(50);
P0=0x00;delayms(50);//先引出单飞
P0=0x01;delayms(50);
P0=0x03;delayms(50);
P0=0x07;delayms(50);
P0=0x0f;delayms(50);
P0=0x1f;delayms(50);
P0=0x3f;delayms(50);
P0=0x7f;delayms(50);
P0=0xff;delayms(50);
P2=0x80;delayms(50);
P2=0xc0;delayms(50);
P2=0xe0;delayms(50);
P2=0xf0;delayms(50);
P2=0xf8;delayms(50);
P2=0xfc;delayms(50);
P2=0xfe;delayms(50);
P2=0xff;delayms(50);
P3=0x80;delayms(50);
P2=0x7f;delayms(50);
P2=0x3f;delayms(50);
P2=0x1f;delayms(50);
P2=0x0f;delayms(50);
P2=0x07;delayms(50);
P2=0x03;delayms(50);
P2=0x01;delayms(50);
P2=0x00;delayms(50);
P3=0x80;delayms(50);
P3=0xc0;delayms(50);
P3=0xe0;delayms(50);
P3=0xf0;delayms(50);
P3=0xf8;delayms(50);
P3=0xfc;delayms(50);
P3=0xfe;delayms(50);
P3=0xff;delayms(50);
P3=0x7f;delayms(50);
P3=0x3f;delayms(50);
P3=0x1f;delayms(50);
P3=0x0f;delayms(50);
P3=0x07;delayms(50);
P3=0x03;delayms(50);
P3=0x01;delayms(50);
P3=0x00;delayms(50);
P1=0x80;delayms(50);
P1=0xc0;delayms(50);
P1=0xe0;delayms(50);
P1=0xf0;delayms(50);
P1=0xf8;delayms(50);
P1=0xfc;delayms(50);
P1=0xfe;delayms(50);
P1=0xff;delayms(50);
P0=0xfe;delayms(50);
P1=0x7f;delayms(50);
P1=0x3f;delayms(50);
P1=0x1f;delayms(50);
P1=0x0f;delayms(50);
P1=0x07;delayms(50);
P1=0x03;delayms(50);
P1=0x01;delayms(50);
P1=0x00;delayms(50);
}
void xs()                 	//一点点消失
{
Onall();delayms(1000);
P0=0x11;P2=0xdf;P1=0xdb;P3=0xef; delayms(1000);
P0=0x59;P2=0x5a;P1=0x52;P3=0x65;delayms(1000);
P0=0xdb;P2=0x42;P1=0x40;P3=0x04;delayms(1000);
P0=0xdf;P2=0x40;P1=0x40;P3=0x00;delayms(1000);
P0=0xff;P2=0x00;P1=0x40;P3=0x00;delayms(1000);Offall();delayms(1000);
}
void zq()			 //桌球
{
Offall();
for(x=6;x>0;x--)
{P0=0xfe;delayms(100);Offall();delayms(50);}
P0=0xff;//第一圈
P0=0xfe;delayms(100);
P0=0xfc; delayms(100);
P0=0xfa; delayms(100);
P0=0xf6; delayms(100);
P0=0xee; delayms(100);
P0=0xce;;delayms(100);
P0=0xae;;delayms(100);
P0=0x6e;delayms(100) ;P0=0xee;
P2=0x80;delayms(100) ;//
P2=0xc0; delayms(100);
P2=0xa0;delayms(100) ;
P2=0x90; delayms(100)  ;
P2=0x88; delayms(100) ;
P2=0x84;delayms(100);
P2=0x82;delayms(100) ;
P2=0x81;delayms(100);P2=0x80;
P3=0x80;delayms(100);//
P3=0xc0; delayms(100);
P3=0xa0; delayms(100);
P3=0x90; delayms(100);
P3=0x88; delayms(100);
P3=0x84;delayms(100);
P3=0x82;delayms(100);
P3=0x81;delayms(100);P3=0x80;
P1=0x80;delayms(100);//
P1=0xc0;delayms(100);
P1=0xa0;delayms(100) ;
P1=0x90;delayms(100)  ;
P1=0x88;delayms(100) ;//
P1=0x8c;delayms(100);
P1=0x8a;delayms(100) ;
P1=0x89;delayms(100); P1=0x88;
P0=0xee;delayms(100);//					  //第二圈
P0=0xec;delayms(100);
P0=0xea;delayms(100);
P0=0xe6;delayms(100);//   //
P0=0xc6;delayms(100);//
P0=0xa6;delayms(100);
P0=0x66;delayms(100);//   //
P2=0x80;delayms(100) ;//
P2=0xc0; delayms(100);
P2=0xa0;delayms(100) ;
P2=0x90; delayms(100)  ;
P2=0x88; delayms(100) ;
P2=0x84;delayms(100);
P2=0x82;delayms(100) ;
P2=0x81;delayms(100);//   //
P3=0x80;delayms(100);//
P3=0xc0; delayms(100);
P3=0xa0; delayms(100);
P3=0x90; delayms(100);
P3=0x88; delayms(100);
P3=0x84;delayms(100);
P3=0x82;delayms(100);
P3=0x81;delayms(100);
P1=0x88;delayms(100);//
P1=0xc8;delayms(100);
P1=0xa8;delayms(100);
P1=0x98;delayms(100);//    //
P1=0x9c;delayms(100);//
P1=0x9a;delayms(100);
P1=0x99;delayms(100);//    //				   
P0=0x66;delayms(100);//					  //第三圈
P0=0x64;delayms(100);
P0=0x62;delayms(100);//    //    //
P0=0x42;delayms(100);//   //
P0=0x22;delayms(100);//
P2=0x81;delayms(100) ;//
P2=0xc1; delayms(100);
P2=0xa1;delayms(100) ;
P2=0x91; delayms(100)  ;
P2=0x89; delayms(100) ;
P2=0x85;delayms(100);
P2=0x83;delayms(100) ;
P3=0x81;delayms(100);//
P3=0xc1; delayms(100);
P3=0xa1; delayms(100);
P3=0x91; delayms(100);
P3=0x89; delayms(100);
P3=0x85;delayms(100);
P3=0x83;delayms(100);
P1=0x99;delayms(100);//
P1=0xd9;delayms(100);
P1=0xb9;delayms(100);
P1=0xbd;delayms(100);//    //
P1=0xbb;delayms(100);//
{for(x=3;x>0;x--){    P0=0x22,P2=0x83,P3=0x83,P1=0xbb,delayms(200),Offall(),delayms(200);    };} 
{for(x=3;x>0;x--){    P0=0xdd,P2=0x7c,P3=0x7c,P1=0x44,delayms(200),Offall(),delayms(200);    };}
{for(x=3;x>0;x--){    P0=0x22,P2=0x83,P3=0x83,P1=0xbb,delayms(200), P0=0xdd,P2=0x7c,P3=0x7c,P1=0x44,delayms(200);    };}
{for(x=5;x>0;x--){    P0=0x22,P2=0x83,P3=0x83,P1=0xbb,delayms(100),Offall(),delayms(100);    };} 
{for(x=5;x>0;x--){    P0=0xdd,P2=0x7c,P3=0x7c,P1=0x44,delayms(100),Offall(),delayms(100);    };}
{for(x=5;x>0;x--){    P0=0x22,P2=0x83,P3=0x83,P1=0xbb,delayms(100), P0=0xdd,P2=0x7c,P3=0x7c,P1=0x44,delayms(100);  };}
{for(x=10;x>0;x--){    P0=0x22,P2=0x83,P3=0x83,P1=0xbb,delayms(50),Offall(),delayms(50);    };} 
{for(x=10;x>0;x--){    P0=0xdd,P2=0x7c,P3=0x7c,P1=0x44,delayms(50),Offall(),delayms(50);    };}
{for(x=10;x>0;x--){    P0=0x22,P2=0x83,P3=0x83,P1=0xbb,delayms(50), P0=0xdd,P2=0x7c,P3=0x7c,P1=0x44,delayms(50);  };}
{for(x=40;x>0;x--){ss(50);}}
}
cdP00(){
P3=0x80;delayms(50);P3=0x00;
P2=0x01;delayms(50);
P2=0x02;delayms(50);
P2=0x04;delayms(50);
P2=0x08;delayms(50);
P2=0x10;delayms(50);
P2=0x20;delayms(50);
P2=0x40;delayms(50);
P2=0x80;delayms(50);P2=0x00;
P0=0xff;
P0=0x7f;delayms(50);
P0=0xbf;delayms(50);
P0=0xdf;delayms(50);
P0=0xef;delayms(50);
P0=0xf7;delayms(50);
P0=0xfb;delayms(50);
P0=0xfd;delayms(50);
P0=0xfe;delayms(50);}//P00 
cdP01(){
P3=0x80;delayms(50);P3=0x00;
P2=0x01;delayms(50);
P2=0x02;delayms(50);
P2=0x04;delayms(50);
P2=0x08;delayms(50);
P2=0x10;delayms(50);
P2=0x20;delayms(50);
P2=0x40;delayms(50);
P2=0x80;delayms(50);P2=0x00;
P0=0x7e;delayms(50);
P0=0xbe;delayms(50);
P0=0xde;delayms(50);
P0=0xee;delayms(50);
P0=0xf6;delayms(50);
P0=0xfa;delayms(50);
P0=0xfc;delayms(50);}//P01
cdP02(){
P3=0x80;delayms(50);P3=0x00;
P2=0x01;delayms(50);
P2=0x02;delayms(50);
P2=0x04;delayms(50);
P2=0x08;delayms(50);
P2=0x10;delayms(50);
P2=0x20;delayms(50);
P2=0x40;delayms(50);
P2=0x80;delayms(50);P2=0x00;
P0=0x7c;delayms(50);
P0=0xbc;delayms(50);
P0=0xdc;delayms(50);
P0=0xec;delayms(50);
P0=0xf4;delayms(50);
P0=0xf8;delayms(50);}//P02
cdP03(){
P3=0x80;delayms(50);P3=0x00;
P2=0x01;delayms(50);
P2=0x02;delayms(50);
P2=0x04;delayms(50);
P2=0x08;delayms(50);
P2=0x10;delayms(50);
P2=0x20;delayms(50);
P2=0x40;delayms(50);
P2=0x80;delayms(50);P2=0x00;
P0=0x78;delayms(50);
P0=0xb8;delayms(50);
P0=0xd8;delayms(50);
P0=0xe8;delayms(50);
P0=0xf0;delayms(50);}//P03
cdP04(){
P3=0x80;delayms(50);P3=0x00;
P2=0x01;delayms(50);
P2=0x02;delayms(50);
P2=0x04;delayms(50);
P2=0x08;delayms(50);
P2=0x10;delayms(50);
P2=0x20;delayms(50);
P2=0x40;delayms(50);
P2=0x80;delayms(50);P2=0x00;
P0=0x70;delayms(50);
P0=0xb0;delayms(50);
P0=0xd0;delayms(50);
P0=0xe0;delayms(50);}//P04
cdP05(){
P3=0x80;delayms(50);P3=0x00;
P2=0x01;delayms(50);
P2=0x02;delayms(50);
P2=0x04;delayms(50);
P2=0x08;delayms(50);
P2=0x10;delayms(50);
P2=0x20;delayms(50);
P2=0x40;delayms(50);
P2=0x80;delayms(50);P2=0x00;
P0=0x60;delayms(50);
P0=0xa0;delayms(50);
P0=0xc0;delayms(50);}//P05
cdP06(){
P3=0x80;delayms(50);P3=0x00;
P2=0x01;delayms(50);
P2=0x02;delayms(50);
P2=0x04;delayms(50);
P2=0x08;delayms(50);
P2=0x10;delayms(50);
P2=0x20;delayms(50);
P2=0x40;delayms(50);
P2=0x80;delayms(50);P2=0x00;
P0=0x40;delayms(50);
P0=0x80;delayms(50);}//P06
cdP07(){
P3=0x80;delayms(50);P3=0x00;
P2=0x01;delayms(50);
P2=0x02;delayms(50);
P2=0x04;delayms(50);
P2=0x08;delayms(50);
P2=0x10;delayms(50);
P2=0x20;delayms(50);
P2=0x40;delayms(50);
P2=0x80;delayms(50);P2=0x00;
P0=0x00;delayms(50);}//P07
cdP27(){
P3=0x80;delayms(50);P3=0x00;
P2=0x01;delayms(50);
P2=0x02;delayms(50);
P2=0x04;delayms(50);
P2=0x08;delayms(50);
P2=0x10;delayms(50);
P2=0x20;delayms(50);
P2=0x40;delayms(50);
P2=0x80;delayms(50);}//P27
cdP26(){
P3=0x80;delayms(50);P3=0x00;
P2=0x81;delayms(50);
P2=0x82;delayms(50);
P2=0x84;delayms(50);
P2=0x88;delayms(50);
P2=0x90;delayms(50);
P2=0xa0;delayms(50);
P2=0xc0;delayms(50);}//P26
cdP25(){
P3=0x80;delayms(50);P3=0x00;
P2=0xc1;delayms(50);
P2=0xc2;delayms(50);
P2=0xc4;delayms(50);
P2=0xc8;delayms(50);
P2=0xd0;delayms(50);
P2=0xc0;delayms(50);}//P25
cdP24(){
P3=0x80;delayms(50);P3=0x00;
P2=0xe1;delayms(50);
P2=0xe2;delayms(50);
P2=0xe4;delayms(50);
P2=0xe8;delayms(50);
P2=0xf0;delayms(50);}//P24
cdP23(){
P3=0x80;delayms(50);P3=0x00;
P2=0xf1;delayms(50);
P2=0xf2;delayms(50);
P2=0xf4;delayms(50);
P2=0xf8;delayms(50);}//P23
cdP22(){
P3=0x80;delayms(50);P3=0x00;
P2=0xf9;delayms(50);
P2=0xfa;delayms(50);
P2=0xfc;delayms(50);}//P22
cdP21(){
P3=0x80;delayms(50);P3=0x00;
P2=0xfd;delayms(50);
P2=0xfe;delayms(50);}//P21
cdP20(){
P3=0x80;delayms(50);P3=0x00;
P2=0xff;delayms(50);}//P20
cdP10(){
P3=0x80;delayms(50)  ;
P3=0x40; delayms(50);
P3=0x20; delayms(50) ;
P3=0x10; delayms(50)  ;
P3=0x08; delayms(50) ;
P3=0x04;delayms(50);
P3=0x02;delayms(50) ;
P3=0x01;delayms(50);P3=0x00;
P1=0x00;
P1=0x80;delayms(50)  ;
P1=0x40; delayms(50);
P1=0x20; delayms(50) ;
P1=0x10; delayms(50)  ;
P1=0x08; delayms(50) ;
P1=0x04;delayms(50);
P1=0x02;delayms(50) ;
P1=0x01;delayms(50); }//P10
cdP11(){
P3=0x80;delayms(50)  ;
P3=0x40; delayms(50);
P3=0x20; delayms(50) ;
P3=0x10; delayms(50)  ;
P3=0x08; delayms(50) ;
P3=0x04;delayms(50);
P3=0x02;delayms(50) ;
P3=0x01;delayms(50);P3=0x00;
P1=0x81;delayms(50);
P1=0x41; delayms(50);
P1=0x21; delayms(50);
P1=0x11; delayms(50);
P1=0x09; delayms(50);
P1=0x05;delayms(50);
P1=0x03;delayms(50);}//P11
cdP12(){
P3=0x80;delayms(50)  ;
P3=0x40; delayms(50);
P3=0x20; delayms(50) ;
P3=0x10; delayms(50)  ;
P3=0x08; delayms(50) ;
P3=0x04;delayms(50);
P3=0x02;delayms(50) ;
P3=0x01;delayms(50);P3=0x00;
P1=0x83;delayms(50);
P1=0x43; delayms(50);
P1=0x23; delayms(50);
P1=0x13; delayms(50);
P1=0x0b; delayms(50);
P1=0x07;delayms(50);}//P12
cdP13(){
P3=0x80;delayms(50)  ;
P3=0x40;delayms(50);
P3=0x20;delayms(50) ;
P3=0x10;delayms(50)  ;
P3=0x08;delayms(50) ;
P3=0x04;delayms(50);
P3=0x02;delayms(50) ;
P3=0x01;delayms(50);P3=0x00;
P1=0x87;delayms(50);
P1=0x47;delayms(50);
P1=0x27;delayms(50);
P1=0x17;delayms(50);
P1=0x0f;delayms(50);}//P13
cdP14(){
P3=0x80;delayms(50)  ;
P3=0x40;delayms(50);
P3=0x20;delayms(50) ;
P3=0x10;delayms(50)  ;
P3=0x08;delayms(50) ;
P3=0x04;delayms(50);
P3=0x02;delayms(50) ;
P3=0x01;delayms(50);P3=0x00;
P1=0x8f;delayms(50);
P1=0x4f;delayms(50);
P1=0x2f;delayms(50);
P1=0x1f;delayms(50);}//P14
cdP15(){
P3=0x80;delayms(50)  ;
P3=0x40;delayms(50);
P3=0x20;delayms(50) ;
P3=0x10;delayms(50)  ;
P3=0x08;delayms(50) ;
P3=0x04;delayms(50);
P3=0x02;delayms(50) ;
P3=0x01;delayms(50);P3=0x00;
P1=0x9f;delayms(50);
P1=0x5f;delayms(50);
P1=0x3f;delayms(50);}//P15
cdP16(){
P3=0x80;delayms(50)  ;
P3=0x40;delayms(50);
P3=0x20;delayms(50) ;
P3=0x10;delayms(50)  ;
P3=0x08;delayms(50) ;
P3=0x04;delayms(50);
P3=0x02;delayms(50) ;
P3=0x01;delayms(50);P3=0x00;
P1=0xbf;delayms(50);
P1=0x7f;delayms(50);}//P16
cdP17(){
P3=0x80;delayms(50)  ;
P3=0x40;delayms(50);
P3=0x20;delayms(50) ;
P3=0x10;delayms(50)  ;
P3=0x08;delayms(50) ;
P3=0x04;delayms(50);
P3=0x02;delayms(50) ;
P3=0x01;delayms(50);P3=0x00;
P1=0xff;delayms(50);}//P17
cdP30(){
P3=0x80;delayms(50);
P3=0x40;delayms(50);
P3=0x20;delayms(50);
P3=0x10;delayms(50);
P3=0x08;delayms(50);
P3=0x04;delayms(50);
P3=0x02;delayms(50);
P3=0x01;delayms(50);}//P30
cdP31(){
P3=0x81;delayms(50);
P3=0x41; delayms(50);
P3=0x21; delayms(50);
P3=0x11; delayms(50);
P3=0x09; delayms(50);
P3=0x05;delayms(50);
P3=0x03;delayms(50);}//P31
cdP32(){
P3=0x83;delayms(50);
P3=0x43; delayms(50);
P3=0x23; delayms(50);
P3=0x13; delayms(50);
P3=0x0b; delayms(50);
P3=0x07;delayms(50);}//P32
cdP33(){
P3=0x87;delayms(50);
P3=0x47;delayms(50);
P3=0x27;delayms(50);
P3=0x17;delayms(50);
P3=0x0f;delayms(50);}//P33
cdP34(){
P3=0x8f;delayms(50);
P3=0x4f;delayms(50);
P3=0x2f;delayms(50);
P3=0x1f;delayms(50);}//P34
cdP35(){
P3=0x9f;delayms(50);
P3=0x5f;delayms(50);
P3=0x3f;delayms(50);}//P35
cdP36(){
P3=0xbf;delayms(50);
P3=0x7f;delayms(50);}//P36
cdP37(){
P3=0xff;delayms(50);}//P37
void cd()	      //由下至上沉淀
{
cdP00();cdP10();cdP01();cdP11();cdP02();cdP12();cdP03();cdP13();cdP04();cdP14();cdP05();cdP15();cdP06();cdP16();cdP07();cdP17();cdP27();
cdP30();
P3=0x81;delayms(50);
P2=0x81;delayms(50);
P2=0x82;delayms(50);
P2=0x84;delayms(50);
P2=0x88;delayms(50);
P2=0x90;delayms(50);
P2=0xa0;delayms(50);
P2=0xc0;delayms(50);//P26
cdP31();
P3=0x83;delayms(50);
P2=0xc1;delayms(50);
P2=0xc2;delayms(50);
P2=0xc4;delayms(50);
P2=0xc8;delayms(50);
P2=0xd0;delayms(50);
P2=0xc0;delayms(50);//P25
cdP32();
P3=0x87;delayms(50);
P2=0xe1;delayms(50);
P2=0xe2;delayms(50);
P2=0xe4;delayms(50);
P2=0xe8;delayms(50);
P2=0xf0;delayms(50);//P24
cdP33();
P3=0x8f;delayms(50);
P2=0xf1;delayms(50);
P2=0xf2;delayms(50);
P2=0xf4;delayms(50);
P2=0xf8;delayms(50);//P23
cdP34();
{P3=0x9f;delayms(50);
P2=0xf9;delayms(50);
P2=0xfa;delayms(50);
P2=0xfc;delayms(50);//P22
cdP35();
P3=0xdf;delayms(50);
P2=0xfd;delayms(50);
P2=0xfe;delayms(50);}//P21
cdP36();
P3=0xff;delayms(50);
P2=0xff;delayms(50);//P20
cdP37();
}
void xfws()		  //小范围闪
{
for(x=10;x>0;x--){P0=0xc3,P1=0x1e,delayms(50);Offall();delayms(50);} //最上
for(x=10;x>0;x--)  {P0=0x3c,P1=0xe1,P2=0x80,delayms(50);Offall();delayms(50);} //第二
for(x=10;x>0;x--)  {P3=0xf0,P2=0x07,delayms(50);Offall();delayms(50);}//最下
for(x=10;x>0;x--)  {P3=0x0f,P2=0x78,delayms(50);Offall();delayms(50);}//第三
for(x=10;x>0;x--)  {P0=0xfc,P1=0x01,P3=0xe0,P2=0x03,delayms(50);Offall();delayms(50);}	//最中间
}
void szsx()			  //左右同时生长（由上至下）
{
Offall();
P0=0xfe;delayms(50);
P0=0xfc;delayms(50);P1=0x01;delayms(50);
P0=0xf8;delayms(50);P1=0x03;delayms(50);
P0=0xf0;delayms(50);P1=0x07;delayms(50);
P0=0xe0;delayms(50);P1=0x0f;delayms(50);
P0=0xc0;delayms(50);P1=0x1f;delayms(50);
P0=0x80;delayms(50);P1=0x3f;delayms(50);
P0=0x00;delayms(50);P1=0x7f;delayms(50);
P2=0x80;delayms(50);P1=0xff;delayms(50);
P2=0xc0;delayms(50);P3=0x01;delayms(50);
P2=0xe0;delayms(50);P3=0x03;delayms(50);
P2=0xf0;delayms(50);P3=0x07;delayms(50);
P2=0xf8;delayms(50);P3=0x0f;delayms(50);
P2=0xfc;delayms(50);P3=0x1f;delayms(50);
P2=0xfe;delayms(50);P3=0x3f;delayms(50);
P2=0xff;delayms(50);P3=0x7f;delayms(50);
P3=0xff;delayms(50);
}
void szxs()					 //左右同时生长（由下至上）
{
Offall();
P3=0x80;delayms(50);
P2=0x01;delayms(50);P3=0xc0;delayms(50);
P2=0x03;delayms(50);P3=0xe0;delayms(50);
P2=0x07;delayms(50);P3=0xf0;delayms(50);
P2=0x0f;delayms(50);P3=0xf8;delayms(50);
P2=0x1f;delayms(50);P3=0xfc;delayms(50);
P2=0x3f;delayms(50);P3=0xfe;delayms(50);
P2=0x7f;delayms(50);P3=0xff;delayms(50);
P2=0xff;delayms(50);P1=0x80;delayms(50);
P0=0x7f;delayms(50);P1=0xc0;delayms(50);
P0=0x3f;delayms(50);P1=0xe0;delayms(50);
P0=0x1f;delayms(50);P1=0xf0;delayms(50);
P0=0x0f;delayms(50);P1=0xf8;delayms(50);
P0=0x07;delayms(50);P1=0xfc;delayms(50);
P0=0x03;delayms(50);P1=0xfe;delayms(50);
P0=0x01;delayms(50);P1=0xff;delayms(50);
P0=0x00;delayms(50);
}
void l1d()						   //1个灯转
{
P0=0xfe,P2=0x80,P3=0x80,P1=0x80;delayms(100);
P0=0xfd,P2=0x40,P3=0x40,P1=0x40;delayms(100);
P0=0xfb,P2=0x20,P3=0x20,P1=0x20;delayms(100);
P0=0xf7,P2=0x10,P3=0x10,P1=0x10;delayms(100);
P0=0xef,P2=0x08,P3=0x08,P1=0x08;delayms(100);
P0=0xdf,P2=0x04,P3=0x04,P1=0x04;delayms(100);
P0=0xbf,P2=0x02,P3=0x02,P1=0x02;delayms(100);
P0=0x7f,P2=0x01,P3=0x01,P1=0x01;delayms(100);
}
void l2d()					   //2个灯转
{
P0=0xfc,P2=0xc0,P3=0xc0,P1=0xc0;delayms(100);
P0=0xf9,P2=0x60,P3=0x60,P1=0x60;delayms(100);
P0=0xf3,P2=0x30,P3=0x30,P1=0x30;delayms(100);
P0=0xe7,P2=0x18,P3=0x18,P1=0x18;delayms(100);
P0=0xcf,P2=0x0c,P3=0x0c,P1=0x0c;delayms(100);
P0=0x9f,P2=0x06,P3=0x06,P1=0x06;delayms(100);
P0=0x3f,P2=0x03,P3=0x03,P1=0x03;delayms(100);
P0=0x7e,P2=0x81,P3=0x81,P1=0x81;delayms(100);
}
void l3d()						   //3个灯转
{
P0=0xf8,P2=0xe0,P3=0xe0,P1=0xe0;delayms(100);
P0=0xf1,P2=0x70,P3=0x70,P1=0x70;delayms(100);
P0=0xe3,P2=0x38,P3=0x38,P1=0x38;delayms(100);
P0=0x8f,P2=0x0e,P3=0x0e,P1=0x0e;delayms(100);
P0=0x1f,P2=0x07,P3=0x07,P1=0x07;delayms(100);
P0=0x3e,P2=0x83,P3=0x83,P1=0x83;delayms(100);
P0=0x7c,P2=0xc1,P3=0xc1,P1=0xc1;delayms(100);
}
void l4d()						    //4个灯转
{
P0=0xf0,P2=0xf0,P3=0xf0,P1=0xf0;delayms(100);
P0=0xe1,P2=0x78,P3=0x78,P1=0x78;delayms(100);
P0=0xc3,P2=0x3c,P3=0x3c,P1=0x3c;delayms(100);
P0=0x87,P2=0x1e,P3=0x1e,P1=0x1e;delayms(100);
P0=0xaf,P2=0x0f,P3=0x0f,P1=0x0f;delayms(100);
P0=0x1e,P2=0x87,P3=0x87,P1=0x87;delayms(100);
P0=0x3c,P2=0xc3,P3=0xc3,P1=0xc3;delayms(100);
P0=0x78,P2=0xe1,P3=0xe1,P1=0xe1;delayms(100);
}
void l5d()							//5个灯转
{
P0=0xe0,P2=0xf8,P3=0xf8,P1=0xf8;delayms(100);
P0=0xc1,P2=0x7c,P3=0x7c,P1=0x7c;delayms(100);
P0=0x83,P2=0x3e,P3=0x3e,P1=0x3e;delayms(100);
P0=0x87,P2=0x1f,P3=0x1f,P1=0x1f;delayms(100);
P0=0x0e,P2=0x8f,P3=0x8f,P1=0x8f;delayms(100);
P0=0x1c,P2=0xc7,P3=0xc7,P1=0xc7;delayms(100);
P0=0x38,P2=0xe3,P3=0xe3,P1=0xe3;delayms(100);
P0=0x70,P2=0xf1,P3=0xf1,P1=0xf1;delayms(100);
}
void l6d()                        //6个灯转
{
P0=0xc0,P2=0xfc,P3=0xfc,P1=0xfc;delayms(100);
P0=0x81,P2=0x7e,P3=0x7e,P1=0x7e;delayms(100);
P0=0x03,P2=0x3f,P3=0x3f,P1=0x3f;delayms(100);
P0=0x06,P2=0x9f,P3=0x9f,P1=0x9f;delayms(100);
P0=0x0c,P2=0xcf,P3=0xcf,P1=0xcf;delayms(100);
P0=0x18,P2=0xe7,P3=0xe7,P1=0xe7;delayms(100);
P0=0x30,P2=0xf3,P3=0xf3,P1=0xf3;delayms(100);
P0=0x60,P2=0xf9,P3=0xf9,P1=0xf9;delayms(100);
}
void main()
{
Onall();delayms(1000);Offall();delayms(1000); 
while(1)
{
cx();//一点点出现
{for(x=20;x>0;x--)ss(50)/* 闪烁20次，50ms */;}
Onall(),delayms(1000), /* 开启所有灯1s  */
zxsw(), /* 正向死亡*/ls(), /* 正向流水  */zxsz(), /* 正向生长  */zxsw() /* 正向死亡  */,fxsz(), /*  反向生长 */fxsw(), /*  反向死亡 */fxls(); /*  反向
流水*/
{for(x=6;x>0;x--)P0=0xfe,delayms(100),P0=0xff,delayms(50);}	 /* P00闪烁6次，50ms  */
szsx();bsb(); /* 半双边流水由上至下  */
szxs();/* 半双边流水，由下至上  */
zq();/* 桌球  */
{for(x=10;x>0;x--){  c(50);    };} /* 间隔闪烁 10次 */
{for(x=10;x>0;x--){  ss(50);   };} /*  闪烁  10次 */
Onall();delayms(500);/* 开启所有灯500ms  */
fxsw(), /*  反向死亡 */
szsx(),	/*  左右同时生长 由上至下 */
zxsw();/* 正向向死亡  */
zxsz();/* 正向生长  */
{for(x=6;x>0;x--)bbs();;} /*  半边交替闪  */
{for(x=6;x>0;x--)sxs();;} /*  上下交替闪  */	
{for(x=30;x>0;x--){  ss(50);};}/* 闪烁   */
Onall();delayms(1000);/* 开启所有灯 1s  */
fbsb();/* 半双边流水 由下至上  */
szxs();/* 左右同时生长 由下至上 */
{for(x=6;x>0;x--)P3=0x80,delayms(100),Offall(),delayms(50);}	 /* P37闪烁6次，50ms  */
cd(); /* 由下至上沉淀  */
fxsw();	/* 反向死亡  */
fxsz();Offall();	/* 反向生长  */
{for(x=6;x>0;x--)bbs();};Offall(); /*  半边交替闪  */
{for(x=6;x>0;x--)sxs();} /*  上下交替闪  */
szxs();/* 左右同时生长 由下至上 */
szsx();/* 左右同时生长 由上至下 */
Offall();/*  关闭所有灯  */
l1d(),l2d(),l3d(),l4d(),l5d(),l6d(),Onall(),delayms(100);//1至6个灯转
{for(x=40;x>0;x--){  ss(50);   };} /*  闪烁  40次 */
xfws();	
Onall();delayms(1000); //开启所有灯 2s
c(1000),c(900),c(800);c(700),c(600),c(500);c(400),c(300),c(200);c(100),c(100);{for(x=20;x>0;x--){  c(50);   };} /*  闪烁  20次 */
szsx();
szxs();
szsx();szsx();szsx();
{for(x=3;x>0;x--){  Onall();delayms(1000);Offall();delayms(500);   };}Onall();delayms(3000);
xs();Offall();delayms(2000); 
}
}	
