#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit s1=P1^0;
sbit s2=P1^1;
sbit s3=P1^2;
sbit s4=P1^3;
sbit s5=P1^4;
sbit s6=P1^5;
sbit s7=P1^6;
sbit lcden=P3^7;
sbit lcdrs=P3^6;
sbit dacs=P3^0;
sbit dawr=P3^1;
uint a=0,ss1=0,ss2=0,ss3=0,ss4=0,ss5=256,bxxz=0;
bit   s1_push,s2_push,s3_push,s4_push,s5_push,s6_push,s7_push,key_push,key;
uchar code table1[]="Wave:Sin";         //正弦波
uchar code table2[]="Wave:Tri";			//三角波
uchar code table3[]="Wave:Zig R";			//锯齿波
uchar code table10[]="Wave:Zig L";
uchar code table4[]="Wave:Rec";			//方波
uchar code table5[]="singal generator"; 
uchar code table6[]="choose wave!";
uchar code table7[]="Please";
uchar code table65[]="F:65 HZ";
uchar code table49[]="F:49 HZ";  
uchar code table39[]="F:39 HZ";
uchar code table33[]="F:33 HZ";
uchar code table28[]="F:28 HZ";
uchar code table24[]="F:24 HZ";
uchar code table22[]="F:22 HZ";
uchar code table20[]="F:20 HZ";  
uchar code table18[]="F:18 HZ";
uchar code table16[]="F:16 HZ";
uchar code table260[]="F:260 HZ";
uchar code table195[]="F:195 HZ";  
uchar code table156[]="F:156 HZ";
uchar code table130[]="F:130 HZ";
uchar code table112[]="F:112 HZ";
uchar code table98[]="F:98 HZ ";
uchar code table87[]="F:87 HZ ";
uchar code table78[]="F:78 HZ ";  
uchar code table71[]="F:71 HZ ";    
uchar code sin[]={
 0x80,0x83,0x86,0x89,0x8c,0x8f,0x92,0x95,0x98,0x9c,0x9f,0xa2,
 0xa5,0xa8,0xab,0xae,0xb0,0xb3,0xb6,0xb9,0xbc,0xbf,0xc1,0xc4,
 0xc7,0xc9,0xcc,0xce,0xd1,0xd3,0xd5,0xd8,0xda,0xdc,0xde,0xe0,
 0xe2,0xe4,0xe6,0xe8,0xea,0xec,0xed,0xef,0xf0,0xf2,0xf3,0xf4,
 0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfc,0xfd,0xfe,0xfe,0xff,
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xfe,
 0xfd,0xfc,0xfc,0xfb,0xfa,0xf9,0xf8,0xf7,0xf6,0xf5,0xf3,0xf2,
 0xf0,0xef,0xed,0xec,0xea,0xe8,0xe6,0xe4,0xe3,0xe1,0xde,0xdc,
 0xda,0xd8,0xd6,0xd3,0xd1,0xce,0xcc,0xc9,0xc7,0xc4,0xc1,0xbf,
 0xbc,0xb9,0xb6,0xb4,0xb1,0xae,0xab,0xa8,0xa5,0xa2,0x9f,0x9c,
 0x99,0x96,0x92,0x8f,0x8c,0x89,0x86,0x83,0x80,0x7d,0x79,0x76,
 0x73,0x70,0x6d,0x6a,0x67,0x64,0x61,0x5e,0x5b,0x58,0x55,0x52,
 0x4f,0x4c,0x49,0x46,0x43,0x41,0x3e,0x3b,0x39,0x36,0x33,0x31,
 0x2e,0x2c,0x2a,0x27,0x25,0x23,0x21,0x1f,0x1d,0x1b,0x19,0x17,
 0x15,0x14,0x12,0x10,0xf,0xd,0xc,0xb,0x9,0x8,0x7,0x6,0x5,0x4,
 0x3,0x3,0x2,0x1,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
 0x0,0x1,0x1,0x2,0x3,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0xc,0xd,
 0xe,0x10,0x12,0x13,0x15,0x17,0x18,0x1a,0x1c,0x1e,0x20,0x23,
 0x25,0x27,0x29,0x2c,0x2e,0x30,0x33,0x35,0x38,0x3b,0x3d,0x40,
 0x43,0x46,0x48,0x4b,0x4e,0x51,0x54,0x57,0x5a,0x5d,0x60,0x63,
 0x66,0x69,0x6c,0x6f,0x73,0x76,0x79,0x7c,0x80};
uchar code Rec[64]={
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0};
uchar code Tri[64]={
0,8,16,24,32,40,48,56,64,72,80,88,96,104,112,120,128,136,144,
152,160,168,176,184,192,200,208,216,224,232,240,248,248,240,
232,224,216,208,200,192,184,176,168,160,152,144,136,128,120,
112,104,96,88,80,72,64,56,48,40,32,24,16,8,0 };

void delayms(uint xms)//延时程序
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}
/*1602显示程序*/
void write_com(uchar com)
{
	lcdrs=0;
	P0=com;
	delayms(5);
	lcden=1;
	delayms(5);
	lcden=0;
}
void write_date(uchar date)
{
	lcdrs=1;
	P0=date;
	delayms(5);
	lcden=1;
	delayms(5);
	lcden=0;
}
void LCD1602_init()	    //1602初始化
{
	lcden=0;
	write_com(0x38);	//设置16*2显示，5*7点阵，8位数据接口
	write_com(0x0c);	//设置开显示，不显示光标
	write_com(0x06);	//写一个字符后地址指针加1
	write_com(0x01);	//清0操作

}
void LCD_init()	
{
	write_com(0x80);
	for(a=0;a<16;a++)
	{
		write_date(table5[a]);
		delayms(5);
	}
	write_com(0x80+0x40);
	for(a=0;a<12;a++)
	{		
		write_date(table6[a]);
		delayms(5);
	}				   

}
void SinWave()    		//正弦波
{
	P2=sin[ss1];
	ss1++;
	if(ss1==256)
		ss1=0;
	
}
void TriWave()    		//三角波
{
	P2=Tri[ss2];
	ss2++;
	if(ss2==64)
		ss2=0;
}
void ZigWaveR()	 		//锯齿波
{	
	P2=ss4;
	ss4++;
	if(ss4==256)
		ss4=0;
	
}
void ZigWaveL()	 		//锯齿波
{
	ss5--;
	P2=ss5;	
	if(ss5==0)
		ss5=256;
	
}
void RecWave()	  		//方波
{	
 	P2=Rec[ss3];
	ss3++;
	if(ss3==64)
		ss3=0;   
}
void f_choose()
{	if(s6_push)
	{
	 	bxxz++;		
		switch(bxxz)
			{
				case 1:
					TH0=250-80;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table49[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table195[a]);
							delayms(5);
						}
					}
					break;
				case 2:
					TH0=250-100;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table39[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table156[a]);
							delayms(5);
						}
					}
					break;
				case 3:
					TH0=250-120;
						if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table33[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table130[a]);
							delayms(5);
						}
					}
					break;
				case 4:
					TH0=250-140;
						if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table28[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table112[a]);
							delayms(5);
						}
					}
					break;
				case 5:
					TH0=250-160;
						if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table24[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table98[a]);
							delayms(5);
						}
					}
					break;
				case 6:
					TH0=250-180;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table22[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table87[a]);
							delayms(5);
						}
					}
					break;
				case 7:
					TH0=250-200;
				if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table20[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table78[a]);
							delayms(5);
						}
					}
					break;
				case 8:
					TH0=250-220;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table18[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table71[a]);
							delayms(5);
						}
					}
					break;
				case 9:
					TH0=250-240;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table16[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table65[a]);
							delayms(5);
						}
					}
					break;
				case 10:
					TH0=250-60;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table65[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table260[a]);
							delayms(5);
						}
					}
					break;
									
		}
		if(bxxz==11)
			bxxz=0;
		if(!s1_push&&!s2_push&&!s3_push&&!s4_push&&!s5_push)
			{
				LCD1602_init();
				write_com(0x80);
				for(a=0;a<6;a++)
				{
					write_date(table7[a]);
					delayms(5);
				}
				write_com(0x80+0x40);
				for(a=0;a<12;a++)
				{		
					write_date(table6[a]);
					delayms(5);
				}		
			}
		
	}
	if(s7_push)
	{
		if(bxxz==0)
			bxxz=10;
		bxxz--;		
		switch(bxxz)
			{
				case 0:
					TH0=250-60;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table65[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table260[a]);
							delayms(5);
						}
					}
					break;
				case 1:
					TH0=250-80;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table49[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table195[a]);
							delayms(5);
						}
					}
					break;
				case 2:
					TH0=250-100;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table39[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table156[a]);
							delayms(5);
						}
					}
					break;
				case 3:
					TH0=250-120;
						if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table33[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table130[a]);
							delayms(5);
						}
					}
					break;
				case 4:
					TH0=250-140;
						if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table28[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table112[a]);
							delayms(5);
						}
					}
					break;
				case 5:
					TH0=250-160;
						if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table24[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table98[a]);
							delayms(5);
						}
					}
					break;
				case 6:
					TH0=250-180;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table22[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table87[a]);
							delayms(5);
						}
					}
					break;
				case 7:
					TH0=250-200;
				if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table20[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table78[a]);
							delayms(5);
						}
					}
					break;
				case 8:
					TH0=250-220;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table18[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<8;a++)
						{
							write_date(table71[a]);
							delayms(5);
						}
					}
					break;
				case 9:
					TH0=250-240;
					if(s1_push|s4_push|s5_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table16[a]);
							delayms(5);
						}
					}
					if(s2_push|s3_push)
					{
						write_com(0x80+0x40);
						for(a=0;a<7;a++)
						{
							write_date(table65[a]);
							delayms(5);
						}
					}
					break;
										
				}
		if(!s1_push&&!s2_push&&!s3_push&&!s4_push&&!s5_push)
			{
				LCD1602_init();
				write_com(0x80);
				for(a=0;a<6;a++)
				{
					write_date(table7[a]);
					delayms(5);
				}
				write_com(0x80+0x40);
				for(a=0;a<12;a++)
				{		
					write_date(table6[a]);
					delayms(5);
				}		
			}
		
	}
	

} 
void keyscan ()
{
	if(s1&&s2&&s3&&s4&&s5&&s6&&s7)
		{
		key=0;
		key_push=0;
		}
	if (!s1&&!key_push)
		{
			key_push=1;
			s1_push=1;
			s2_push=0;
			s3_push=0;
			s4_push=0;
			s5_push=0;
		}
	if (!s2&&!key_push)
		{
			key_push=1;
			s2_push=1;
			s1_push=0;
			s3_push=0;
			s4_push=0;
			s5_push=0;
		}
	if (!s3&&!key_push)
		{
			key_push=1;
			s3_push=1;
			s2_push=0;
			s1_push=0;
			s4_push=0;
			s5_push=0;
		}
	if (!s4&&!key_push)
		{
			key_push=1;
			s4_push=1;
			s2_push=0;
			s3_push=0;
			s1_push=0;
			s5_push=0;
		}
	if (!s5&&!key_push)
		{
			key_push=1;
			s4_push=0;
			s2_push=0;
			s3_push=0;
			s1_push=0;
			s5_push=1;
		}
	if(!s6&&!key)
		{
			key=1;
			s6_push=1;
		}
	else	s6_push=0;
	if(!s7&&!key)
		{
			key=1;
			s7_push=1;
		}
	else	s7_push=0;
	
} 

void keycheck ()
{
	if(s1_push&&key_push)

		{
			TH0=256-60;
			bxxz=0;
			TR0=1;
			LCD1602_init();
			write_com(0x80);  
			for(a=0;a<8;a++)
			{		
				write_date(table1[a]);
				delayms(1);
			}
			write_com(0x80+0x40);
			for(a=0;a<7;a++)
			{
				write_date(table65[a]);
				delayms(5);
			}							//虽然s1_push&&key_push为一个低电平触发变量，但由于以上延时，			
										//使这个操作只被执行一次
		}
	
	if(s2_push&&key_push)

		{
		  	TH0=256-60;
			bxxz=0;
			TR0=1;
			LCD1602_init();
			write_com(0x80);
			for(a=0;a<8;a++)
			{		
				write_date(table2[a]);
				delayms(1);
			}
			write_com(0x80+0x40);
			for(a=0;a<8;a++)
			{
				write_date(table260[a]);
				delayms(5);
			}
				
		}

	if(s3_push&&key_push)

		{
		  	TH0=256-60;
			bxxz=0;
			TR0=1;
			LCD1602_init();
			write_com(0x80);
			for(a=0;a<8;a++)
			{		
				write_date(table4[a]);
				delayms(1);
			}
			write_com(0x80+0x40);
			for(a=0;a<8;a++)
			{
				write_date(table260[a]);
				delayms(5);
			}
				
		}
	
	if(s4_push&&key_push)
	{
		TH0=256-60;
		bxxz=0;
		TR0=1;
		LCD1602_init();
		write_com(0x80);
		for(a=0;a<10;a++)
		{		
			write_date(table3[a]);
			delayms(1);
		}
		write_com(0x80+0x40);
		for(a=0;a<7;a++)
		{
			write_date(table65[a]);
			delayms(5);
		}
	}
	if(s5_push&&key_push)
	{
		TH0=256-60;
		bxxz=0;
		TR0=1;
		LCD1602_init();
		write_com(0x80);
		for(a=0;a<10;a++)
		{		
			write_date(table10[a]);
			delayms(1);
		}
		write_com(0x80+0x40);
		for(a=0;a<7;a++)
		{
			write_date(table65[a]);
			delayms(5);
		}
	}
//	delayms(10);
//	while(!s1&&!s2&&!s3&&!s4);
/*	if (s6==0)
	{
		delayms(10);
		if(s6==0)
		{
//			s5_push=1;
			
			f_choose();
			while(!s6);
		}	
	}
//	else
//		s5_push=0;
*/	
}
void init ()
{
	dacs=0;
	dawr=0;
	TMOD=0x02;
  	TH0=256-60;
	TL0=256-60;
	EA=1;
	ET0=1;
}

void main()
{
	init ();
    LCD1602_init();
	LCD_init();
	while(1)
	{
		keyscan ();
		keycheck ();
		f_choose();

	}
}


void T0_time()interrupt 1
{
	if(s1_push)
		SinWave();
	if(s2_push)
		TriWave();
	if(s3_push)
		RecWave();
	if(s4_push)
		ZigWaveR();
	if(s5_push)
		ZigWaveL();
			
}