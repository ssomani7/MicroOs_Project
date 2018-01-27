#include "system.h"


char getch(){
	char c=0;
	while(c==0)
		c=get_last_key();

	discard_last_key();
	return c;
}

int strcmp(char* m1,char* m2){

	int len1 = strlen(m1);
	int len2 = strlen(m2);
	
	int i=0;
	if(len1!=len2)
		return -1;

	for(i=0;i<len1;i++){
		if(m1[i]!=m2[i])
			return -1;
	}
	 return 0;
}

void getcmd(char cmd[],int n){

	int i=0,bufchar=0;;
	char c;

	while(i<n){
		bufchar=1;
		c = getch();
		if(c=='\n')
			break;
		else if(c=='\b'){
			printch(c);
			bufchar=0;
			i--;
		}

		if(bufchar){
			printch(c);
			cmd[i++]=c;
		}
	}

	cmd[i] = '\0';
	printch('0'+i);
}

void shell(char* cmd)
{
    if(strcmp(cmd,"help")==0)
        help();
    else if(strcmp(cmd,"clear")==0)
        clear_screen();
    else if(strcmp(cmd,"echo")==0)
    	echo(cmd);
    else
        print("\nInvalid Command\n");
	
}