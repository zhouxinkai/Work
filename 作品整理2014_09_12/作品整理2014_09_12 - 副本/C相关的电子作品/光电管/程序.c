#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit en=P2^2;
sbit rw=P2^1;
sbit rs=P2^0;
sbit bell=P2^7;
uchar code table[]="0123456789";
uchar num=0,flag0=0,flag1=0,bai,shi,ge;

void delay(uint xms) 		//��ʱ�Ӻ���
{	
	uint i,j;
	for(i=xms;i>0;i--)
 		for(j=110;j>0;j--);
}

void write_com(uchar com)	//д�����Ӻ���
{
	rs=0;
	P0=com;
	delay(5);
	en=1;
	delay(5);
	en=0;
}

void write_data(uchar date)		//д�����Ӻ���
{
	rs=1;
	P0=date;
	delay(5);
	en=1;
	delay(5);
	en=0;
}

void int_lcd()			//1602��ʼ���Ӻ���
{
	rw=0;				//д״̬	
	en=0;
	write_com(0x38);		//16*2��ʾ��5*7����8λ���ݽӿ�
	write_com(0x0c);		//����ʾ������ʾ��꣬��겻��˸
	write_com(0x06);		//дһ���ַ����ַָ���1(������Ӧ�ÿ��Բ�д��)
	write_com(0x01);		//����1602�ϵ�ʱ�ĺڰߣ�����ָ����0		
}

void int_interrupt()		//�жϳ�ʼ���Ӻ���
{
	EA=1;		//�����ж�		
	IT0=0;		//INT0�ĵ�ƽ�Ӹߵ��͵ĸ�������Ч
	IT1=0;
	EX0=1;		//���ⲿ�ж�0
	EX1=1;
}

void display(uchar num)		//1602��ʾ�Ӻ���
{
	bell=1;
	write_com(0x80+0x06);	//��1602��һ�е�7λ��ʾ��λ
	write_data(table[bai]);
	delay(10);
	write_com(0x80+0x07);	//��1602��һ�е�8λ��ʾʮλ
	write_data(table[shi]);
	delay(10);	
	write_com(0x80+0x08);	//��1602��һ�е�9λ��ʾ��λ
	write_data(table[ge]);
	delay(10);
	
}						

void main()					//������
{
	int_interrupt();	
	int_lcd();
	while(1)
	{
			 
		
		display(num);
	}
}

void INT0_add()interrupt 0			//�жϺ���int0
{
	PX0=0;PX1=1;							//�ⲿ�ж�0����Ϊ�����ȼ��жϣ��Ա�����γ��ж�Ƕ��
	flag0=1;					//�������ⲿ�ж�0ʱ��־λflag0Ϊ1
	flag1=1;					//��־λflag1ȡ������ֹMCUδ��Ӧ�ⲿ�ж�1,num��1
	delay(100);						//��ʱ0.5�룬�ȴ��ⲿ�ж�1
	if(flag1==0)					//�ж��Ƿ�����ⲿ�ж�1
		{
			num++;	
			bai=num/100;		
			shi=num%100/10;
			ge=num%10;		
		}
	if(num==10)			//�����������1602��ʾ����201����0,���ҷ���������	
		{
			bell=0;
			delay(100);	//����1s
			bell=1;
			num=0;	
		}				   	   
	flag0=0;PX0=0;PX1=1;					//��־λflag0ȡ��������MCU����Ӧ�ⲿ�ж�0
									
}
void INT1_reduce()interrupt 2		//�жϺ���int1
{
	PX1=0;PX0=1;							//�ⲿ�ж�0����Ϊ�����ȼ��жϣ��Ա�����γ��ж�Ƕ��
	flag1=1;					//�������ⲿ�ж�0ʱ��־λflag0Ϊ1
	flag0=1;					//��־λflag0ȡ������ֹMCUδ��Ӧ�ⲿ�ж�0,num��1
	delay(100);						//��ʱ0.5�룬�ȴ��ⲿ�ж�0						
	if(flag0==0)					//�ж��Ƿ�����ⲿ�ж�1					
		{
			num--;	
			bai=num/100;		
			shi=num%100/10;
			ge=num%10;		
		}
	flag1=0;PX1=0;PX0=1;					//��־λflag0ȡ��������MCU����Ӧ�ⲿ�ж�1
}

/*�ó�������Ҫ��̵�����жϺ��ж�Ƕ�׵ĸ��ͬʱ�õ��˶Գ�˼��������ж����ȼ�*/
