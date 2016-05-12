#include<gtk/gtk.h>
double a,b; //参与运算的两个变量
double p=0;	//
int xsd;	//小数点
int method;	//运算法则
int principle;	//当前的进制
int flag=0;
char out[100]="0";
GtkWidget *window;	//窗口
GtkWidget *vbox;	//垂直框
GtkWidget *table1;	//表格1
GtkWidget *table2;	//表格2
GSList *group;	//供给radio用
GtkWidget *radio;	//单选按钮，虽然有4个，但只定义一个，用来选择进制
GtkWidget *entry;	//文本框，用来显示输入与输出
GtkWidget *entry1;
/***************以下是42个普通按钮，用来存放0~9,A~F,sin,cos，+-*=等一些运算符号**************************/
GtkWidget *button1;	
GtkWidget *button2;	
GtkWidget *button3;	
GtkWidget *button4;
GtkWidget *button5;	
GtkWidget *button6;	
GtkWidget *button7;	
GtkWidget *button8;	
GtkWidget *button9;	
GtkWidget *button10;
GtkWidget *button11;	
GtkWidget *button12;	
GtkWidget *button13;	
GtkWidget *button14;	
GtkWidget *button15;	
GtkWidget *button16;	
GtkWidget *button17;	
GtkWidget *button18;	
GtkWidget *button19;	
GtkWidget *button20;	
GtkWidget *button21;	
GtkWidget *button22;	
GtkWidget *button23;	
GtkWidget *button24;	
GtkWidget *button25;	
GtkWidget *button26;	
GtkWidget *button27;	
GtkWidget *button28;	
GtkWidget *button29;	
GtkWidget *button30;	
GtkWidget *button31;	
GtkWidget *button32;	
GtkWidget *button33;	
GtkWidget *button34;	
GtkWidget *button35;	
GtkWidget *button36;	
GtkWidget *button37;	
GtkWidget *button38;	
GtkWidget *button39;	
GtkWidget *button40;	
GtkWidget *button41;	
GtkWidget *button42;	
