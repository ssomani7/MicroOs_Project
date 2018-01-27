#include "system.h"
#include "../drivers/display.h"
void help()
{
	print("\nWelcome to MicroOS");
    print("\nT.E. Mini Project");
    print("\nGroup D10\n 39 - Shashi Bhushan Mishra");
    print("\n43 - Siddharth Kumar");
    print("\n44 - Saurabh Somani");
    print("\n47 - Yashodhan Tak ");
        
}

void clear()
{
	clear_screen();
}

void echo(char* cmd){

    print(cmd);
}

void *memcpy(void *dest, const void *src, int count)
{
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(; count != 0; count--) *dp++ = *sp++;
    return dest;
}

void *memset(void *dest, char val, Size_t count)
{
    char *temp = (char *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, Size_t count)
{
    unsigned short *temp = (unsigned short *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

Size_t strlen(const char *str)
{
    Size_t retval;
    for(retval = 0; *str != '\0'; str++) retval++;
    return retval;
}

unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}


int main()
{
    unsigned char c, d[10] ;
    c = 'a';
    char cmd[10];
	char *video_memory = (char*)0xb8000 ;
	*video_memory = 'y';
	clear_screen();
	print("\n          MicroOS             \n");
	timer_install();
    gdt_install();
    idt_install();
    isrs_install();
    irq_install();
    keyboard_install();
    print("\n-----------------------------------");
    while(1){
    print("\nmicroOS>> ");
    

	//putch();
	__asm__ __volatile__ ("sti");
    
    
       getcmd(cmd,10);
       //print(cmd);
       shell(cmd);
        
        }

    //puts("Hello World!\n");

    for (;;);

	return 0; 
}
