#include<gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
//#include"myhead.h"
//#include"interface.c"
void on_clicked(GtkWidget *widget,gpointer data)
{
    char temp[50],*tempchar;
    strcpy(temp,gtk_entry_get_text(GTK_ENTRY(entry)));
    int prin=principle;
    switch(prin)
    {
        case 16: tempchar="(Hex)";
                 break;
        case 10: tempchar="(Dec)";
                 break;
        case 8: tempchar="(Oct)";
                 break;
        case 2: tempchar="(Bin)";
                 break;
    }
    if(GTK_TOGGLE_BUTTON(widget)->active)
    {
        if((char *)data=="Hex")
        {
            hex();
            principle=16;
            conversion(temp,prin,principle);
            gtk_entry_set_text(GTK_ENTRY(entry1),temp);
            gtk_entry_append_text(GTK_ENTRY(entry1),tempchar);
            gtk_entry_set_text(GTK_ENTRY(entry),out);
            if(flag==0) flag=1;
            a=0;
            b=0;
            method=0;
            xsd=0;
//xsd=0;
        }
        if((char *)data=="Dec")
        {
            dec();
            principle=10;
            conversion(temp,prin,principle);
            gcvt(p,50,out);     //该库函数将十进制浮点数转换成十进制的字符串
            gtk_entry_set_text(GTK_ENTRY(entry1),temp);
            gtk_entry_append_text(GTK_ENTRY(entry1),tempchar);
            gtk_entry_set_text(GTK_ENTRY(entry),out);
            if(flag==0) flag=1;
            a=0;
            b=0;
            method=0;
            xsd=0;
        }
        if((char *)data=="Oct")
        {
            oct();
            principle=8;
            conversion(temp,prin,principle);
            gtk_entry_set_text(GTK_ENTRY(entry1),temp);
            gtk_entry_append_text(GTK_ENTRY(entry1),tempchar);
            gtk_entry_set_text(GTK_ENTRY(entry),out);
            if(flag==0) flag=1;
            a=0;
            b=0;
            method=0;
            xsd=0;
        }
        if((char *)data=="Bin")
        {
            bin();
            principle=2;
            conversion(temp,prin,principle);
            gtk_entry_set_text(GTK_ENTRY(entry1),temp);
            gtk_entry_append_text(GTK_ENTRY(entry1),tempchar);
            gtk_entry_set_text(GTK_ENTRY(entry),out);
            if(flag==0) flag=1;
            a=0;
            b=0;
            method=0;
            xsd=0;
        }
    }
}
void create()
{
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),g_locale_to_utf8("我的计算器  作者:周新凯",-1,NULL,NULL,NULL));
//    gtk_container_border_width(GTK_CONTAINER(window),100);
    gtk_widget_set_uposition(window,500,200);
    vbox=gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window),vbox);
    gtk_widget_show(vbox);
    table1=gtk_table_new(3,4,FALSE);
    gtk_box_pack_start(GTK_BOX(vbox),table1,TRUE,FALSE,0);
    gtk_widget_show(table1);
    table2=gtk_table_new(9,5,TRUE);
    gtk_box_pack_start(GTK_BOX(vbox),table2,TRUE,FALSE,0);
    gtk_widget_show(table2);
    entry1=gtk_entry_new();
    entry=gtk_entry_new();
    gtk_table_attach(GTK_TABLE(table1),entry1,0,4,0,1,(GtkAttachOptions)(GTK_EXPAND|GTK_FILL),(GtkAttachOptions)(0),0,0);
    gtk_widget_show(entry1);
    gtk_table_attach(GTK_TABLE(table1),entry,0,4,1,2,(GtkAttachOptions)(GTK_EXPAND|GTK_FILL),(GtkAttachOptions)(0),0,0);
    gtk_widget_show(entry);



    /*******************以下是42个按钮的定义及显示**********************************/
    /*****************************第一列************************************/
    button2=gtk_button_new_with_mnemonic("sin");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button2,0,1,0,1,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);
    gtk_widget_set_size_request(button2,54,32);    // 设置/获得构件大小


    button9=gtk_button_new_with_mnemonic("X^2");    //带助记符的按钮
    gtk_widget_show(button9);                       //一直显示
    gtk_table_attach(GTK_TABLE(table2),button9,0,1,1,2,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    
    button13=gtk_button_new_with_mnemonic("1/X");    //带助记符的按钮
    gtk_widget_show(button13);                       //一直显示
    gtk_table_attach(GTK_TABLE(table2),button13,0,1,2,3,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    button33=gtk_button_new_with_mnemonic("D");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button33,0,1,3,4,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    
    button18=gtk_button_new_with_mnemonic("A");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button18,0,1,4,5,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);



    button14=gtk_button_new_with_mnemonic("7");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button14,0,1,5,6,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    
    button15=gtk_button_new_with_mnemonic("4");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button15,0,1,6,7,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);



    button16=gtk_button_new_with_mnemonic("1");    //带助记符的按钮
    gtk_widget_show(button16);                       //一直显示
    gtk_table_attach(GTK_TABLE(table2),button16,0,1,7,8,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    
    button17=gtk_button_new_with_mnemonic("0");    //带助记符的按钮
    gtk_widget_show(button17);                       //一直显示
    gtk_table_attach(GTK_TABLE(table2),button17,0,1,8,9,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);
    


    /*****************************第2列**********************************/
    button3=gtk_button_new_with_mnemonic("cos");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button3,1,2,0,1,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    button8=gtk_button_new_with_mnemonic("X^3");    //带助记符的按钮
    gtk_widget_show(button8);                       //一直显示
    gtk_table_attach(GTK_TABLE(table2),button8,1,2,1,2,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    
    button12=gtk_button_new_with_mnemonic("n!");    //带助记符的按钮
    gtk_widget_show(button12);                       //一直显示
    gtk_table_attach(GTK_TABLE(table2),button12,1,2,2,3,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    button38=gtk_button_new_with_mnemonic("E");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button38,1,2,3,4,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    
    button23=gtk_button_new_with_mnemonic("B");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button23,1,2,4,5,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);



    button19=gtk_button_new_with_mnemonic("8");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button19,1,2,5,6,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    
    button20=gtk_button_new_with_mnemonic("5");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button20,1,2,6,7,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);



    button21=gtk_button_new_with_mnemonic("2");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button21,1,2,7,8,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    
    button27=gtk_button_new_with_mnemonic(".");    //带助记符的按钮
    gtk_widget_show(button27);                       //一直显示
    gtk_table_attach(GTK_TABLE(table2),button27,1,2,8,9,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    /***************************以下是第三列**********************************/
    button4=gtk_button_new_with_mnemonic("tan");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button4,2,3,0,1,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    button7=gtk_button_new_with_mnemonic("X^y");    //带助记符的按钮
    gtk_widget_show(button7);                       //一直显示
    gtk_table_attach(GTK_TABLE(table2),button7,2,3,1,2,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    
    button1=gtk_button_new_with_mnemonic("Pi");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button1,2,3,2,3,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    button42=gtk_button_new_with_mnemonic("F");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button42,2,3,3,4,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    
    button28=gtk_button_new_with_mnemonic("C");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button28,2,3,4,5,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);



    button24=gtk_button_new_with_mnemonic("9");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button24,2,3,5,6,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    
    button25=gtk_button_new_with_mnemonic("6");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button25,2,3,6,7,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);



    button26=gtk_button_new_with_mnemonic("3");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button26,2,3,7,8,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    
    button22=gtk_button_new_with_mnemonic("+/-");    //带助记符的按钮
    gtk_widget_show(button22);                       //一直显示
    gtk_table_attach(GTK_TABLE(table2),button22,2,3,8,9,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    /***************************以下是第4列**********************************/
    button10=gtk_button_new_with_mnemonic("ln");    //带助记符的按钮
    gtk_widget_show(button10);
    gtk_table_attach(GTK_TABLE(table2),button10,3,4,0,1,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    button11=gtk_button_new_with_mnemonic("log");    //带助记符的按钮
    gtk_widget_show(button11);                       //一直显示
    gtk_table_attach(GTK_TABLE(table2),button11,3,4,1,2,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    
    button6=gtk_button_new_with_mnemonic("Exp");    //带助记符的按钮
    gtk_table_attach(GTK_TABLE(table2),button6,3,4,2,3,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    button35=gtk_button_new_with_mnemonic("And");    //带助记符的按钮
    gtk_widget_show(button35);
    gtk_table_attach(GTK_TABLE(table2),button35,3,4,3,4,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    
    button36=gtk_button_new_with_mnemonic("OR");    //带助记符的按钮
    gtk_widget_show(button36);
    gtk_table_attach(GTK_TABLE(table2),button36,3,4,4,5,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);



    button40=gtk_button_new_with_mnemonic("Xor");    //带助记符的按钮
    gtk_widget_show(button40);
    gtk_table_attach(GTK_TABLE(table2),button40,3,4,5,6,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    
    button30=gtk_button_new_with_mnemonic("X");    //带助记符的按钮
    gtk_widget_show(button30);
    gtk_table_attach(GTK_TABLE(table2),button30,3,4,6,7,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    
    button32=gtk_button_new_with_mnemonic("+");    //带助记符的按钮
    gtk_widget_show(button32);
    gtk_table_attach(GTK_TABLE(table2),button32,3,4,7,8,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    button5=gtk_button_new_with_mnemonic("=====");
    gtk_widget_show(button5);
    gtk_table_attach(GTK_TABLE(table2),button5,3,5,8,9,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    /**********************************以下是第5列********************************************************/
    button34=gtk_button_new_with_mnemonic("ON/C");
    gtk_widget_show(button34);
    gtk_table_attach(GTK_TABLE(table2),button34,4,5,0,3,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    button39=gtk_button_new_with_mnemonic("Not");    //带助记符的按钮
    gtk_widget_show(button39);
    gtk_table_attach(GTK_TABLE(table2),button39,4,5,3,4,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);

    
    button41=gtk_button_new_with_mnemonic("Int");    //带助记符的按钮
    gtk_widget_show(button41);
    gtk_table_attach(GTK_TABLE(table2),button41,4,5,4,5,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);



    button37=gtk_button_new_with_mnemonic("Mod");    //带助记符的按钮
    gtk_widget_show(button37);
    gtk_table_attach(GTK_TABLE(table2),button37,4,5,5,6,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    
    button29=gtk_button_new_with_mnemonic("/");    //带助记符的按钮
    gtk_widget_show(button29);
    gtk_table_attach(GTK_TABLE(table2),button29,4,5,6,7,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);


    
    button31=gtk_button_new_with_mnemonic("-");    //带助记符的按钮
    gtk_widget_show(button31);
    gtk_table_attach(GTK_TABLE(table2),button31,4,5,7,8,(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(GTK_FILL),0,0);





    /*******************************以下是4个单选按钮的建立及功能定义******************************************************/
    radio=gtk_radio_button_new_with_label(NULL,g_locale_to_utf8("16进制",-1,NULL,NULL,NULL));
    g_signal_connect(GTK_OBJECT(radio),"clicked",G_CALLBACK(on_clicked),(void *)"Hex");
    gtk_table_attach(GTK_TABLE(table1),radio,0,1,2,3,(GtkAttachOptions)(GTK_EXPAND|GTK_FILL),(GtkAttachOptions)(0),0,0);
    gtk_widget_show(radio);

    group=gtk_radio_button_group(GTK_RADIO_BUTTON(radio));
    radio=gtk_radio_button_new_with_label(group,g_locale_to_utf8("10进制",-1,NULL,NULL,NULL));
    g_signal_connect(GTK_OBJECT(radio),"clicked",G_CALLBACK(on_clicked),(void *)"Dec");
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio),TRUE);
    gtk_table_attach(GTK_TABLE(table1),radio,1,2,2,3,(GtkAttachOptions)(GTK_EXPAND|GTK_FILL),(GtkAttachOptions)(0),0,0);
    gtk_widget_show(radio);


    group=gtk_radio_button_group(GTK_RADIO_BUTTON(radio));
    radio=gtk_radio_button_new_with_label(group,g_locale_to_utf8("8进制",-1,NULL,NULL,NULL));
    g_signal_connect(GTK_OBJECT(radio),"clicked",G_CALLBACK(on_clicked),(void *)"Oct");
    gtk_table_attach(GTK_TABLE(table1),radio,2,3,2,3,(GtkAttachOptions)(GTK_EXPAND|GTK_FILL),(GtkAttachOptions)(0),0,0);
    gtk_widget_show(radio);


    group=gtk_radio_button_group(GTK_RADIO_BUTTON(radio));
    radio=gtk_radio_button_new_with_label(group,g_locale_to_utf8("2进制",-1,NULL,NULL,NULL));
    g_signal_connect(GTK_OBJECT(radio),"clicked",G_CALLBACK(on_clicked),(void *)"Bin");
    gtk_table_attach(GTK_TABLE(table1),radio,3,4,2,3,(GtkAttachOptions)(GTK_EXPAND|GTK_FILL),(GtkAttachOptions)(0),0,0);
    gtk_widget_show(radio);
}
/*int main()
{
    create();
    printf("linux\n");
    return 0;
}*/
