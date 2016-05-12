#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit en=P2^2;
sbit rw=P2^1;
sbit rs=P2^0;
sbit bell=P2^7;
uchar code table[]="0123456789";
uchar num=0,flag0=0,flag1=0,bai,shi,ge;

void delay(uint xms) 		//延时子函数
{	
	uint i,j;
	for(i=xms;i>0;i--)
 		for(j=110;j>0;j--);
}

void write_com(uchar com)	//写命令子函数
{
	rs=0;
	P0=com;
	delay(5);
	en=1;
	delay(5);
	en=0;
}

void write_data(uchar date)		//写数据子函数
{
	rs=1;
	P0=date;
	delay(5);
	en=1;
	delay(5);
	en=0;
}

void int_lcd()			//1602初始化子函数
{
	rw=0;				//写状态	
	en=0;
	write_com(0x38);		//16*2显示，5*7点阵，8位数据接口
	write_com(0x0c);		//开显示，不显示光标，光标不闪烁
	write_com(0x06);		//写一个字符后地址指针加1(这个语句应该可以不写吧)
	write_com(0x01);		//消除1602上电时的黑斑，数据指针清0		
}

void int_interrupt()		//中断初始化子函数
{
	EA=1;		//开总中断		
	IT0=0;		//INT0的电平从高到低的负跳变有效
	IT1=0;
	EX0=1;		//开外部中断0
	EX1=1;
}

void display(uchar num)		//1602显示子函数
{
	bell=1;
	write_com(0x80+0x06);	//在1602第一行第7位显示百位
	write_data(table[bai]);
	delay(10);
	write_com(0x80+0x07);	//在1602第一行第8位显示十位
	write_data(table[shi]);
	delay(10);	
	write_com(0x80+0x08);	//在1602第一行第9位显示个位
	write_data(table[ge]);
	delay(10);
	
}						

void main()					//主函数
{
	int_interrupt();	
	int_lcd();
	while(1)
	{
			 
		
		display(num);
	}
}

void INT0_add()interrupt 0			//中断函数int0
{
	PX0=0;PX1=1;							//外部中断0定义为低优先级中断，以便可以形成中断嵌套
	flag0=1;					//当触发外部中断0时标志位flag0为1
	flag1=1;					//标志位flag1取反，防止MCU未响应外部中断1,num加1
	delay(100);						//延时0.5秒，等待外部中断1
	if(flag1==0)					//判断是否进入外部中断1
		{
			num++;	
			bai=num/100;		
			shi=num%100/10;
			ge=num%10;		
		}
	if(num==10)			//这个数用来送1602显示，到201后清0,并且蜂鸣器报警	
		{
			bell=0;
			delay(100);	//报警1s
			bell=1;
			num=0;	
		}				   	   
	flag0=0;PX0=0;PX1=1;					//标志位flag0取反，表明MCU已响应外部中断0
									
}
void INT1_reduce()interrupt 2		//中断函数int1
{
	PX1=0;PX0=1;							//外部中断0定义为低优先级中断，以便可以形成中断嵌套
	flag1=1;					//当触发外部中断0时标志位flag0为1
	flag0=1;					//标志位flag0取反，防止MCU未响应外部中断0,num减1
	delay(100);						//延时0.5秒，等待外部中断0						
	if(flag0==0)					//判断是否进入外部中断1					
		{
			num--;	
			bai=num/100;		
			shi=num%100/10;
			ge=num%10;		
		}
	flag1=0;PX1=0;PX0=1;					//标志位flag0取反，表明MCU已响应外部中断1
}

/*该程序重在要深刻的理解中断和中断嵌套的概念，同时用到了对称思想和设置中断优先级*/
