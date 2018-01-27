
char* inttostring(int num){

	int q,r;
	char string[6];
	int count =0;
	while(num != 0){
		r = num % 10;
		q = num / 10 ;
		string[count++] = '0'+r;
		num = q;
	}
	string[count] ='\0';
	return string;
}


void strreverse(char *msg){
	int i,j;
	int len = strlen(msg);
	char c;
	for(i=0,j=len-1;i<len/2;i++,j--){
		c=msg[i];
		msg[i] = msg[j];
		msg[i]=c;		
	}
	//return msg;
}

