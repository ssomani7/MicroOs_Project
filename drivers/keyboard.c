#include <stdint.h>
#include "display.h"
#include "../kernel/system.h"


int cmd_length=0;
char cmd[100]={'\0'};

unsigned char c=0,x;
char get_last_key(){
    return c;
}

void discard_last_key(){
    c=0;    
}
void clear_cmd(char cmd[])
{
    int i=0;
    for(i=0 ; i!=100;i++)
    {
        cmd[i] = '\0'; 
    }
}


void keyboard_handler()
{
	int i=0,j =0,valid=0,inst=0;
    unsigned char ip_arr[100] = {'\0'};
    char ip_ptr;
    
    unsigned int scancode,key;
    unsigned short temp;
     
    scancode = inportb(0x60);
    key = scancode;
    if(scancode < 0x39)
        valid = 1;
    if (scancode == 0x02)
    {
        c = '1';
        //print("1");
    }
    else if(scancode == 0x03)
    {
        c = '2';
        //print("2");
    }
    else if(scancode == 0x04)
    {
        c = '3';
        //print("3");
    }
    else if(scancode == 0x05)
    {
        c = '4';
        //print("4");
    }
    else if(scancode == 0x06)
    {
        c = '5';
        //print("5");
    }
    else if(scancode == 0x07)
    {
        c = '6';
        //print("6");
    }
    else if(scancode == 0x08)
    {
        c = '7';
        //print("7");
    }
    else if(scancode == 0x09)
    {
        c = '8';
        //print("8");
    }
    else if(scancode == 0x0a)
    {
        c = '9';
        //print("9");
    }
    else if(scancode == 0x0b)
    {
        c = '0';
        //print("0");
    }
    else if(scancode == 0x0c)
    {
        c = '-';
        //print("-");
    }
    else if(scancode == 0x0d)
    {
        c = '=';
        //print("=");
    }
    else if(scancode == 0x0e) //Backspace
    {
        c = '\b';
        //print("\b");
    }
    else if(scancode == 0x0f) // Tab
    {
        c = '\t';
        print(" ");

    }
    else if(scancode == 0x010)
    {
        c = 'q';
        //print("q");
    }
    else if(scancode == 0x11)
    {
        c = 'w';
        //print("w");
    }
    else if(scancode == 0x12)
    {
        c = 'e';
        //print("e");
    }
    else if(scancode == 0x13)
    {
        c = 'r';
        //print("r");
    }
    else if(scancode == 0x14)
    {
        c = 't';
        //print("t");
    }
    else if(scancode == 0x15)
    {
        c = 'y';
        //print("y");
    }
    else if(scancode == 0x16)
    {
        c = 'u';
        //print("u");
    }
    else if(scancode == 0x17)
    {
        c = 'i';
        //print("i");
    }
    else if(scancode == 0x18)
    {
        c = 'o';
        //print("o");
    }
    else if(scancode == 0x19)
    {
        c = 'p';
        //print("p");
    }
    else if(scancode == 0x1a)
    {
        c = '[';
        //print("[");
    }
    else if(scancode == 0x1b)
    {
        c = ']';
        //print("]");
    }
    else if(scancode == 0x1c) //Enter
    {
        valid = 0;
        c = '\n';
        //print("\n");
    }
    else if(scancode == 0x1e)
    {
        c = 'a';
        //print("a");
    }
    else if(scancode == 0x1f)
    {
        c = 's';
        //print("s");
    }
    else if(scancode == 0x20)
    {
        c = 'd';
        //print("d");
    }
    else if(scancode == 0x21)
    {
        c = 'f';
        //print("f");
    }
    else if(scancode == 0x22)
    {
        c = 'g';
        //print("g");
    }
    else if(scancode == 0x23)
    {
        c = 'h';
        //print("h");
    }
    else if(scancode == 0x24)
    {
        c = 'j';
        //print("j");
    }
    else if(scancode == 0x25)
    {
        c = 'k';
        //print("k");
    }
    else if(scancode == 0x26)
    {
        c = 'l';
        //print("l");
    }
    else if(scancode == 0x27)
    {
        c = ';';
        //print(";");
    }
    else if(scancode == 0x28)
    {
       c = '\'';
       //print("'");
    }
    else if(scancode == 0x29)
    {
        c = '`';
        //print("`");
    }
    else if(scancode == 0x2b)
    {
        c = '\\';
        //print("\\");
    }
    else if(scancode == 0x2c)
    {
        c = 'z';
        //print("z");
    }
    else if(scancode == 0x2d)
    {
        c = 'x';
        //print("x");
    }
    else if(scancode == 0x2e)
    {
        c = 'c';
        //print("c");
    }
    else if(scancode == 0x2f)
    {
        c = 'v';
        //print("v");
    }
    else if(scancode == 0x30)
    {
        c = 'b';
        //print("b");
    }
    else if(scancode == 0x31)
    {
        c = 'n';
        //print("n");
    }
    else if(scancode == 0x32)
    {
        c = 'm';
        //print("m");
    }
    else if(scancode == 0x33)
    {
        c = ',';
        //print(",");
    }
    else if(scancode == 0x34)
    {
        c = '.';
        //print(".");
    }
    else if(scancode == 0x35)
    {
        c = '/';
        //print("/");
    }
    else if(scancode == 0x39)
    {
        c = ' ';
        //print(" ");
    }
    
  
    outportb(0x20,0x20);
    
}   

/* Installs the keyboard handler into IRQ1 */
void keyboard_install()
{
    print("\nKeyboard Intalled....");
    irq_install_handler(1, keyboard_handler);
}
