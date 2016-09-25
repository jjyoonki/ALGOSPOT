/*
4번 커밋 시 커맨트 : "4소 commit"
*/
#include <stdio.h>
#include <string.h>
#define NUMC 16	// 시계수 
#define NUMB 10	// 버튼수 

int matrix[NUMB][NUMC] = {
{1,1,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0},
{0,0,0,1,0, 0,0,1,0,1, 0,1,0,0,0, 0},
{0,0,0,0,1, 0,0,0,0,0, 1,0,0,0,1, 1},
{1,0,0,0,1, 1,1,1,0,0, 0,0,0,0,0, 0},
{0,0,0,0,0, 0,1,1,1,0, 1,0,1,0,0, 0},

{1,0,1,0,0, 0,0,0,0,0, 0,0,0,0,1, 1},
{0,0,0,1,0, 0,0,0,0,0, 0,0,0,0,1, 1},
{0,0,0,0,1, 1,0,1,0,0, 0,0,0,0,1, 1},
{0,1,1,1,1, 1,0,0,0,0, 0,0,0,0,0, 0},
{0,0,0,1,1, 1,0,0,0,1, 0,0,0,1,0, 0}
};
int clock[NUMC];

int min( int a, int b ){
	if( a<b )
		return(a);
	else
		return(b);
}
void push_button( int b0 ){
	int c;

	for( c=0 ; c<NUMC ; c++ ){
		if( matrix[b0][c] )
			clock[c] = (clock[c]+1)%4;
	}
	return;
}
int is_aligned(){
	int c;
	
	for( c=0 ; c<NUMC ; c++ ){
		if( clock[c] )
			return(0);
	}
	return(1);
}
void init(){
	int c, h;

	for( c=0 ; c<NUMC ; c++ ){
		scanf( "%d", &h );
		clock[c] = (h/3)%4;
	}
}
void prn(){
	int c, y, x;

	for( y=0,c=0 ; y<4 ; y++ ){
		for( x=0 ; x<4 ; x++,c++ )
			printf( "%2d ", clock[c] );
		printf( "\n" );
	}
	printf( "\n" );
}

int check( int b0 ){
	int p, nump;

	nump = 100000;
	if( b0==NUMB ){
		if( is_aligned() )
			return(0);
		else
			return(nump);
	}
 
	for( p=0 ; p<4 ; p++ ){
		nump = min( nump, p+check(b0+1) );
		push_button(b0);
	}
	return(nump);
}
int main(void) {
	int T, num;

	scanf( "%d", &T );
	while(T--){
		init();
		num = check(0);
		if( num==100000 )
			num = -1;
		printf( "%d\n", num );
	}

	return 0;
}
