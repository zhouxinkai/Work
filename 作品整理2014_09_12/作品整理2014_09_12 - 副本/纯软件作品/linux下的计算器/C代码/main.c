#include<gtk/gtk.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include"myhead.h"
#include"interface.c"
#include"conversion.c"
#include"signal.c"
#include"create.c"
int main(int argc,char *argv[])
{
    a=0;
    b=0;
    method=0;
    principle=10;
    xsd=0;
    gtk_set_locale();
    gtk_rc_add_default_file("./gtkrc.zh_CN");
    gtk_init(&argc,&argv);
    create();
    addsignal();
    gtk_widget_show(window);
    gtk_main();
    return 0;
}
