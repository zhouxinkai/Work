#include<gtk/gtk.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"myhead.h"
//#include"conversion.c"
void bin_operation()   //该函数将文本框中的各种进制的字符串转换成十进制浮点数
{
    char num[50];
    strcpy(num,gtk_entry_get_text(GTK_ENTRY(entry)));   //获取文本框内容
    if(a==0)    //如果a为空，则赋于其值
    {
        if(principle==16)
        {
            conversion(num,16,10);
            a=p;
        }
        if(principle==10)
        {
            a=atof(num);
        }
        if(principle==8)
        {
            conversion(num,8,10);
            a=p;
        }
        if(principle==2)
        {
            conversion(num,2,10);
            a=p;
        }
    }
    else
    {
        if(principle==16)
        {
            conversion(num,16,10);
            b=p;
        }
        if(principle==10)
        {
            b=atof(num);
        }
        if(principle==8)
        {
            conversion(num,8,10);
            b=p;
        }
        if(principle==2)
        {
            conversion(num,2,10);
            b=p;
        }
    }
    xsd=0;  //表示已经没有小数点
    gtk_entry_set_text(GTK_ENTRY(entry1),num);
    gtk_entry_set_text(GTK_ENTRY(entry),"");
}
void right_output() //该函数将最终运算结果（十进制浮点数）转换成想要进制对应的字符串，显示到文本框中
{
    char num[50];
    gcvt(a,50,num);     //该库函数将十进制浮点数转换成十进制的字符串
    if(principle==16)
    {
        conversion(num,10,16);
        gtk_entry_set_text(GTK_ENTRY(entry),out);
    }
    if(principle==10)
    {
        gtk_entry_set_text(GTK_ENTRY(entry),num);
    }
    if(principle==8)
    {
        conversion(num,10,8);
        gtk_entry_set_text(GTK_ENTRY(entry),out);
    }
    if(principle==2)
    {
        conversion(num,10,2);
        gtk_entry_set_text(GTK_ENTRY(entry),out);
    }
    a=0;
    b=0;
    method=0;
}
float jiechen(int c)    //递归函数法求阶乘
{
    float d;
    if(c==0||c==1)  d=1;
    else d=jiechen(c-1)*c;
    return d;
}
void output()
{
    char num[50]="0";
//    gtk_entry_set_text(GTK_ENTRY(entry),"");
        strcpy(num,gtk_entry_get_text(GTK_ENTRY(entry)));
        gtk_entry_append_text(GTK_ENTRY(entry1),num);
        if(flag==0) flag=1;
        if(principle==16)
        {
            conversion(num,16,10);
            b=p;
        }
        if(principle==10)
        {
            b=atof(num);
        }
        if(principle==8)
        {
            conversion(num,8,10);
            b=p;
        }
        if(principle==2)
        {
            conversion(num,2,10);
            b=p;
        }
        if(a==0&&b==0)
        {
            gtk_entry_set_text(GTK_ENTRY(entry1),"0=");
            gtk_entry_set_text(GTK_ENTRY(entry),"0");

        }
        else
        {
            switch(method)
            {
                case 0: a=a+b;
                        right_output();
                        break;
                case 1: a=a-b;
                        right_output();
                        break;
                case 2: a=a*b;
                        right_output();
                        break;
                case 3:
                        if(b==0)
                        {
                            a=0;
                            b=0;
                            method=0;
                            gtk_entry_set_text(GTK_ENTRY(entry),g_locale_to_utf8("除数不能为零",-1,NULL,NULL,NULL));
                        }
                        else
                        {
                            a=a/b;  //C语言规定两个整数相除只取商的部分，但一个整数除以浮点数结果仍是浮点数
                            right_output();
                        }
                        break;
                case 4:
                        a=pow(a,b);
                        right_output();
                        break;
                case 5:
                        a=((int)a)&((int)b);
                        right_output();
                        break;
                case 6:
                        a=((int)a)|((int)b);
                        right_output();
                        break;
                case 7:
                        a=((int)a)^((int)b);
                        right_output();
                        break;
                case 8:
                        if(b==0)
                        {
                            a=0;
                            b=0;
                            method=0;
                            gtk_entry_set_text(GTK_ENTRY(entry),g_locale_to_utf8("除数不能为零",-1,NULL,NULL,NULL));
                        }
                        else
                        {
                            a=((int)a)%((int)b);    //C语言规定取余只能用于两个整数之间
                            right_output();
                        }
                        break;
                case 9:
                        a=sin(b);
                        right_output();
                        break;
                case 10:
                        a=cos(b);
                        right_output();
                        break;
                case 11:
                        a=tan(b);
                        right_output();
                        break;
                case 12:
                        a=exp(b);
                        right_output();
                        break;
                case 13:
                        a=b*b*b;
                        gtk_entry_append_text(GTK_ENTRY(entry1),"^3");
                        right_output();
                        break;
                case 14:
                        a=b*b;
                        gtk_entry_append_text(GTK_ENTRY(entry1),"^2");
                        right_output();
                        break;
                case 15:
                        if(b<=0)
                        {
                            a=0;
                            b=0;
                            method=0;
                            gtk_entry_set_text(GTK_ENTRY(entry),g_locale_to_utf8("对数必须为正数",-1,NULL,NULL,NULL));
                        }
                        else
                        {
                            a=log(b);
                            right_output();
                        }
                        break;
                case 16:
                        if(b<=0)
                        {
                            a=0;
                            b=0;
                            method=0;
                            gtk_entry_set_text(GTK_ENTRY(entry),g_locale_to_utf8("对数必须为正数",-1,NULL,NULL,NULL));
                        }
                        else
                        {
                            a=log10(b);
                            right_output();
                        }
                        break;
                case 17:
                        if(b<0)
                        {
                            a=0;
                            b=0;
                            method=0;
                            gtk_entry_set_text(GTK_ENTRY(entry),g_locale_to_utf8("阶乘不能为负数",-1,NULL,NULL,NULL));
                        }
                        else
                        {
                            a=jiechen((int)b);
                            gtk_entry_append_text(GTK_ENTRY(entry1),"!");
                            right_output();
                        }
                        break;
                case 18:
                        if(b==0)
                        {
                            a=0;
                            b=0;
                            method=0;
                            gtk_entry_set_text(GTK_ENTRY(entry),g_locale_to_utf8("除数不能为零",-1,NULL,NULL,NULL));
                        }
                        else
                        {
                            a=1/b;
                            right_output();
                        }
                        break;
                case 19:
                        a=~((int)b);
                        right_output();
                        break;
                case 20:
                        a=floor(b);
                        right_output();
                        break;
            }
            gtk_entry_append_text(GTK_ENTRY(entry1),"=");
        }
    
}
void add(GtkWidget *widget,gpointer data)  //加法函数
{
    method=0;
    bin_operation();
    gtk_entry_append_text(GTK_ENTRY(entry1),"+");
}
void sub(GtkWidget *widget,gpointer data)  //减法函数
{
    method=1;
    bin_operation();
    gtk_entry_append_text(GTK_ENTRY(entry1),"-");
}
void mul(GtkWidget *widget,gpointer data)  //乘法函数
{
    method=2;
    bin_operation();
    gtk_entry_append_text(GTK_ENTRY(entry1),"X");
}
void Div(GtkWidget *widget,gpointer data)  //除法函数
{
    method=3;
    bin_operation();
    gtk_entry_append_text(GTK_ENTRY(entry1),"/");
}
void Pow(GtkWidget *widget,gpointer data)  //幂函数
{
    method=4;
    bin_operation();
    gtk_entry_append_text(GTK_ENTRY(entry1),"^");
}
void and(GtkWidget *widget,gpointer data)  //与函数
{
    method=5;
    bin_operation();
    gtk_entry_append_text(GTK_ENTRY(entry1),"&");
}
void or(GtkWidget *widget,gpointer data)  //或函数
{
    method=6;
    bin_operation();
    gtk_entry_append_text(GTK_ENTRY(entry1),"|");
}
void xor(GtkWidget *widget,gpointer data)  //异或函数
{
    method=7;
    bin_operation();
    gtk_entry_append_text(GTK_ENTRY(entry1),"^");
}
void mod(GtkWidget *widget,gpointer data)  //取余函数，取模
{
    method=8;
    bin_operation();
    gtk_entry_append_text(GTK_ENTRY(entry1),"%");
}
void Sin(GtkWidget *widget,gpointer data)  //Sin函数
{
    method=9;
    flag=0;
    gtk_entry_set_text(GTK_ENTRY(entry1),"sin");
    gtk_entry_set_text(GTK_ENTRY(entry),"");
}
void Cos(GtkWidget *widget,gpointer data)  //Cos函数
{
    method=10;
    flag=0;
    gtk_entry_set_text(GTK_ENTRY(entry1),"cos");
    gtk_entry_set_text(GTK_ENTRY(entry),"");
}
void Tan(GtkWidget *widget,gpointer data)  //Tan函数
{
    method=11;
    flag=0;
    gtk_entry_set_text(GTK_ENTRY(entry1),"tan");
    gtk_entry_set_text(GTK_ENTRY(entry),"");
}
void Exp(GtkWidget *widget,gpointer data)  //求e的x次方
{
    method=12;
    flag=0;
    gtk_entry_set_text(GTK_ENTRY(entry1),"e^");
    gtk_entry_set_text(GTK_ENTRY(entry),"");
}
void cube(GtkWidget *widget,gpointer data) //立方函数
{
    method=13;
    flag=0;
}
void square(GtkWidget *widget,gpointer data)    //平方函数
{
    method=14;
    flag=0;
}
void log_e(GtkWidget *widget,gpointer data)    //ln函数
{
    method=15;
    flag=0;
    gtk_entry_set_text(GTK_ENTRY(entry1),"ln");
    gtk_entry_set_text(GTK_ENTRY(entry),"");
}
void log_10(GtkWidget *widget,gpointer data)   //lg函数
{
    method=16;
    flag=0;
    gtk_entry_set_text(GTK_ENTRY(entry1),"log");
    gtk_entry_set_text(GTK_ENTRY(entry),"");
}
void factorial(GtkWidget *widget,gpointer data)      //阶乘函数
{
    method=17;
    flag=0;
}
void inverse(GtkWidget *widget,gpointer data)        //求倒数函数
{
    method=18;
    flag=0;
    gtk_entry_set_text(GTK_ENTRY(entry1),"1/");
    gtk_entry_set_text(GTK_ENTRY(entry),"");
}
void not(GtkWidget *widget,gpointer data)            //取反函数
{
    method=19;
    flag=0;
    gtk_entry_set_text(GTK_ENTRY(entry1),"~");
    gtk_entry_set_text(GTK_ENTRY(entry),"");
}
void Floor(GtkWidget *widget,gpointer data)    //取整函数
{
    method=20;
    flag=0;
    gtk_entry_set_text(GTK_ENTRY(entry1),"Int");
    gtk_entry_set_text(GTK_ENTRY(entry),"");
}
void hasxsd(GtkWidget *widget,gpointer data)    //如果没有小数点，则加入一个小数点
{
    if(xsd==0)
    {
        gtk_entry_append_text(GTK_ENTRY(entry),gtk_button_get_label(widget));  //往文本框添加字符串（从后面添加）
        xsd=1;
    }
}
void sign(GtkWidget *widget,gpointer data)         //正负号输入函数
{
    char num[50];
    float c;
    strcpy(num,gtk_entry_get_text(GTK_ENTRY(entry)));
    c=atof(num);    //把字符串转换成十进制浮点数
    c=-c;
    gcvt(c,32,num); //把十进制浮点数转换成字符串
    gtk_entry_set_text(GTK_ENTRY(entry),num);
}
void clear(GtkWidget *widget,gpointer data)
{
    gtk_entry_set_text(GTK_ENTRY(entry1),"");
    gtk_entry_set_text(GTK_ENTRY(entry),"");
    xsd=0;
    a=0;
    b=0;
    method=0;
}
void input(GtkWidget *widget,gpointer data)
{
    if(flag==1) 
    {
        gtk_entry_set_text(GTK_ENTRY(entry1),"");
        gtk_entry_set_text(GTK_ENTRY(entry),"");
        flag=0;
    }
    gtk_entry_append_text(GTK_ENTRY(entry),gtk_button_get_label(widget));
}
void input_pi(GtkWidget *widget,gpointer data)
{
    gtk_entry_set_text(GTK_ENTRY(entry),"3.14159265358979323846264");
}
void addsignal()
{
    /************************以下17个按钮实现数字的输入********************************/
    g_signal_connect(G_OBJECT(button1),"clicked",G_CALLBACK(input_pi),NULL);
    g_signal_connect(G_OBJECT(button14),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button15),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button16),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button17),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button18),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button19),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button20),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button21),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button23),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button24),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button25),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button26),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button28),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button33),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button38),"clicked",G_CALLBACK(input),NULL);
    g_signal_connect(G_OBJECT(button42),"clicked",G_CALLBACK(input),NULL);
    /*************************以下21个按钮实现相应运算*******************************/
    g_signal_connect(G_OBJECT(button2),"clicked",G_CALLBACK(Sin),NULL);
    g_signal_connect(G_OBJECT(button3),"clicked",G_CALLBACK(Cos),NULL);
    g_signal_connect(G_OBJECT(button4),"clicked",G_CALLBACK(Tan),NULL);
    g_signal_connect(G_OBJECT(button6),"clicked",G_CALLBACK(Exp),NULL);
    g_signal_connect(G_OBJECT(button7),"clicked",G_CALLBACK(Pow),NULL);
    g_signal_connect(G_OBJECT(button8),"clicked",G_CALLBACK(cube),NULL);
    g_signal_connect(G_OBJECT(button9),"clicked",G_CALLBACK(square),NULL);
    g_signal_connect(G_OBJECT(button10),"clicked",G_CALLBACK(log_e),NULL);
    g_signal_connect(G_OBJECT(button11),"clicked",G_CALLBACK(log_10),NULL);
    g_signal_connect(G_OBJECT(button12),"clicked",G_CALLBACK(factorial),NULL);
    g_signal_connect(G_OBJECT(button13),"clicked",G_CALLBACK(inverse),NULL);
    g_signal_connect(G_OBJECT(button29),"clicked",G_CALLBACK(Div),NULL);
    g_signal_connect(G_OBJECT(button30),"clicked",G_CALLBACK(mul),NULL);
    g_signal_connect(G_OBJECT(button31),"clicked",G_CALLBACK(sub),NULL);
    g_signal_connect(G_OBJECT(button32),"clicked",G_CALLBACK(add),NULL);
    g_signal_connect(G_OBJECT(button35),"clicked",G_CALLBACK(and),NULL);
    g_signal_connect(G_OBJECT(button36),"clicked",G_CALLBACK(or),NULL);
    g_signal_connect(G_OBJECT(button37),"clicked",G_CALLBACK(mod),NULL);
    g_signal_connect(G_OBJECT(button39),"clicked",G_CALLBACK(not),NULL);
    g_signal_connect(G_OBJECT(button40),"clicked",G_CALLBACK(xor),NULL);
    g_signal_connect(G_OBJECT(button41),"clicked",G_CALLBACK(Floor),NULL);
    /********************以下4个按钮为特殊按钮*************************/
    g_signal_connect(G_OBJECT(button5),"clicked",G_CALLBACK(output),NULL);
    g_signal_connect(G_OBJECT(button22),"clicked",G_CALLBACK(sign),NULL);
    g_signal_connect(G_OBJECT(button27),"clicked",G_CALLBACK(hasxsd),NULL);
    g_signal_connect(G_OBJECT(button34),"clicked",G_CALLBACK(clear),NULL);
    /******************以下这个中断信号使计算器退出线程****************************/
    g_signal_connect(G_OBJECT(window),"delete envnt",gtk_main_quit,NULL);//空间和消息函数创建关联
}
/*int main()
{
    printf("signal\n");
    return 0;
}*/
