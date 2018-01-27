
#include "../kernel/system.h"


int timer_ticks = 0,secs=0;
void timer_handler(struct regs *r)
{ 
    timer_ticks++;
    if (timer_ticks % 18 == 0)
        secs++;
}


void timer_wait(int ticks)
{
    unsigned long eticks;
    eticks = timer_ticks + ticks;
    while(timer_ticks < eticks);
}



void timer_install()
{
	print("\nTimer has started....");
    irq_install_handler(0, timer_handler);
}
