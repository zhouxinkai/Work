#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//#include"myhead.h"
//char out[50];
//double p;
char num1[100]="0.8125";
int conversion(char num[100],int t,int n)
{
    int x,l,i,ii,j,c,z;
    int h[50],b[50];
    double d,r;
    memset(out,0,100);//每次调用函数，先将存储结果的字符串数组清0
    l=strlen(num);
    ii=0;
    p=0;    //每次调用函数，先将存储结果的变量p清0
    x=l;
    for(i=0;i<l;i++)
    {
        if(num[i]=='.')
        {
            x=i;    //如果有小数点，则x指向小数点
            break;
        }
    }
    /****
    **以下为将num[]中的字符串转换成十进制,并放在变量p中
    **
    ****/
    /***************以下为整数部分的转换**********************/
    for(i=x-1;i>=0;i--)
    {
        if(num[i]=='-') break;
        switch(num[i])
        {
            case 'A': r=10;
                      break;
            case 'B': r=11;
                      break;
            case 'C': r=12;
                      break;
            case 'D': r=13;
                      break;
            case 'E': r=14;
                      break;
            case 'F': r=15;
                      break;
            default: r=num[i]-'0';
        }
        p=p+r*(pow((double)t,(double)(x-1-i)));
    }
    /**************以下为小数部分的转换********************/
    if(num[x]=='.') //如果有小数部分，则进行转换
    {
        for(i=x+1;i<l;i++)
        {
            switch(num[i])
            {
                case 'A': r=10;
                          break;
                case 'B': r=11;
                          break;
                case 'C': r=12;
                          break;
                case 'D': r=13;
                          break;
                case 'E': r=14;
                          break;
                case 'F': r=15;
                          break;
                default: r=num[i]-'0';
            }
            p=p+r*(pow((double)t,(double)(x-i)));
            if(i>=x+16)   break;  //主要处理死循环的情况
        }
    }
    if(n==10)   //如果要转换成十进制
    {
        if(num[0]=='-') p=-p;
    }
    else    //如果要转换成其他进制
    {
        z=(int)p;   //取整
        i=0;
        if(z==0)    out[ii++]='0';
        while(z)    //整数部分为除基取余再逆序，直到商为0,并放在h[]中
        {
            h[i++]=z%n;
            z=z/n;
        }
        c=0;
        if(p!=(int)p)   //是否有小数部分
        {
            d=p-(int)p;
            while(d!=0) //小数部分为乘基取整再顺序，直到为0，并放在b[]中
            {
                b[c]=(int)(d*n);
                d=d*n-b[c];
                c++;
                if(i>=15)   break;  //主要处理死循环的情况
            }
        }
        if(num[0]=='-')
        {
            out[0]='-';
            ii++;
        }
        for(j=i-1;j>=0;j--,ii++)    //  将整数部分h[]中的元素逆序放在out[]中
        {
            switch(h[j])
            {
                case 10: out[ii]='A';
                         break;
                case 11: out[ii]='B';
                         break;
                case 12: out[ii]='C';
                         break;
                case 13: out[ii]='D';
                         break;
                case 14: out[ii]='E';
                         break;
                case 15: out[ii]='F';
                         break;
                case 9: out[ii]='9';
                         break;
                case 8: out[ii]='8';
                         break;
                case 7: out[ii]='7';
                         break;
                case 6: out[ii]='6';
                         break;
                case 5: out[ii]='5';
                         break;
                case 4: out[ii]='4';
                         break;
                case 3: out[ii]='3';
                         break;
                case 2: out[ii]='2';
                         break;
                case 1: out[ii]='1';
                         break;
                case 0: out[ii]='0';
                         break;
            }
        }
        if(p!=(int)p)   //如果有小数部分，则进行输出
        {
            out[ii++]='.';
            for(j=0;j<c;j++,ii++)//将小数部分b[]中的元素顺序放在out[]中
            {
                switch(b[j])
                {
                    case 10: out[ii]='A';
                             break;
                    case 11: out[ii]='B';
                             break;
                    case 12: out[ii]='C';
                             break;
                    case 13: out[ii]='D';
                             break;
                    case 14: out[ii]='E';
                             break;
                    case 15: out[ii]='F';
                             break;
                    case 9: out[ii]='9';
                            break;
                    case 8: out[ii]='8';
                            break;
                    case 7: out[ii]='7';
                            break;
                    case 6: out[ii]='6';
                            break;
                    case 5: out[ii]='5';
                            break;
                    case 4: out[ii]='4';
                            break;
                    case 3: out[ii]='3';
                            break;
                    case 2: out[ii]='2';
                            break;
                    case 1: out[ii]='1';
                            break;
                    case 0: out[ii]='0';
                            break;
                }
            }
            out[ii]='\0';
        }
    }
    return 0;
}
/*int main()
{
    int i;
    conversion(num1,10,2);
    for(i=0;out[i];i++)
        printf("%c",out[i]);
    printf("\n");
    printf("%f\n",p);   //注意转换成十进制时没放在out[]字符数组中，而是直接放在变量p中
    return 0;
}*/
