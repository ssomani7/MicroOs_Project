
# define VIDEO_ADDRESS 0xb8000 // Video Memory
# define MAX_ROWS 25
# define MAX_COLS 80
# define WHITE_ON_BLACK 0x0f // Attribute byte
# define REG_SCREEN_CTRL 0x3D4
# define REG_SCREEN_DATA 0x3D5

int CUR_X=0;
int CUR_Y=0;


void update_cursor(int row, int col)  // updates Cursor Position
 {
    unsigned short position=(row*80) + col;
 
    port_byte_out(0x3D4, 0x0F);
    port_byte_out(0x3D5, (unsigned char)(position&0xFF));
    port_byte_out(0x3D4, 0x0E);
    port_byte_out(0x3D5, (unsigned char )((position>>8)&0xFF));
 }

void set_cursor(int offset)
 {
    unsigned short position=offset/2;
 
    port_byte_out(0x3D4, 0x0F);
    port_byte_out(0x3D5, (unsigned char)(position&0xFF));
    port_byte_out(0x3D4, 0x0E);
    port_byte_out(0x3D5, (unsigned char )((position>>8)&0xFF));
 }

int get_screen_offset( int row,int col) // Returns offset to the video memory
{

	CUR_X = row;
	CUR_Y = col;
	return ((row * 80) + col) *2 ;

}

int get_cursor(){
	return ((CUR_X * 80) + CUR_Y ) *2 ;
}



int handle_scrolling( int cursor_offset ) {

	int i ;
	if ( cursor_offset < MAX_ROWS * MAX_COLS *2) {
	return cursor_offset ;
	}


	for ( i =1; i < MAX_ROWS ; i++) {
	memcpy ( get_screen_offset(i-1 , 0 ) + VIDEO_ADDRESS,
		get_screen_offset(i ,0) + VIDEO_ADDRESS ,
		MAX_COLS *2
		);
	}

	char *last_line = get_screen_offset(MAX_ROWS -1,0) + VIDEO_ADDRESS ;
	for ( i =0; i < MAX_COLS *2; i ++) {
		last_line [ i ] = 0;
	}

	cursor_offset -= 2* MAX_COLS ;

	return cursor_offset ;
}



void print_char(unsigned char character ,int col , int row , char attribute_byte){

	unsigned char *vidmem = ( unsigned char *) VIDEO_ADDRESS ;
	if(!attribute_byte){
		attribute_byte = WHITE_ON_BLACK;
	}

	int offset;
	if(col >= 0 && row >=0){
		offset = get_screen_offset(row,col );
	}
	else
		offset = get_cursor();

	if(character == '\n'){
		CUR_Y =0;
		CUR_X++;
		offset = get_screen_offset(CUR_X , CUR_Y );
	}
	else if(character == '\b'){
		
		vidmem[offset-2] = ' ';
		CUR_Y--;
		vidmem[offset+1]=attribute_byte;
		offset = get_screen_offset(CUR_X , CUR_Y );
		update_cursor(CUR_X,CUR_Y);

	}
	else{
		CUR_Y++;
		vidmem[offset] = character;
		vidmem[offset+1]=attribute_byte;
	}

	offset = get_screen_offset(CUR_X , CUR_Y );
	offset = handle_scrolling(offset);
	set_cursor(offset);
	
}
void printch(unsigned char character )
{
	print_char(character,-1,-1,WHITE_ON_BLACK);
}

void print_at ( char* message , int col , int row ) {
	if ( col >= 0 && row >= 0) {
		update_cursor( col , row );
	}
	int i = 0;
	while ( message [ i ] != 0) {
		print_char ( message[i++] , col , row , WHITE_ON_BLACK );
	}
}

void print(char* message){
	print_at(message,-1,-1);
}

void clear_screen () {
	int row = 0;
	int col = 0;
	for ( row =0; row < MAX_ROWS ; row++) {
		for ( col =0; col < MAX_COLS ; col++) {
			print_char( ' ' , col , row , WHITE_ON_BLACK );
			}
		}
		CUR_X=CUR_Y=0;
		update_cursor(0,0);
}