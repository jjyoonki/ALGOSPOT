WEB 상에서 변경 (브랜치B)
/* 

HH CODE
IN>
1		// 게임판
URLPM
XPRET
GIAET
XTNZY
XOQRS
6		// 찾을 단어
PRETTY
GIRL
  :

OUT>
PRETTY YES
GIRL NO
  :
*/
#include <stdio.h>
#include <string.h>

#define BMAX 5	//
#define NMAX 10

char board[BMAX][BMAX];
char cache[BMAX][BMAX][10];
int candidateY[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
int candidateX[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int N;

int _find( char *word, int y0, int x0, int n, int slen ){
	int m, y, x;

	if( n==slen )
		return(1);
	if( cache[y0][x0][n-1] )
		return(0);

	for( m=0 ; m<8 ; m++ ){
		y = y0+candidateY[m];
		x = x0+candidateX[m];
		if( 0<=y && y<BMAX && 0<=x && x<BMAX && board[y][x]==word[n] ){
			if( _find( word, y, x, n+1, slen ) )
				return(1);
		}
	}

	cache[y0][x0][n-1] = 1;
	return(0);
}


int find( char *word, int slen ){
	int y, x;

	for( y=0 ; y<BMAX ; y++ ){
		for( x=0 ; x<BMAX ; x++ ){
			if( board[y][x]==word[0] ){
				if( _find( word, y, x, 1, slen ) )
					return(1);
			}
		}
	}
	return(0);
}
void init(){
	int y, x;
	char ch;

	for( y=0 ; y<BMAX ; y++ ){
		for( x=0 ; x<BMAX ; x++ ){
			scanf( "%c", &ch );
			while( ch==' ' || ch=='\n' )
				scanf( "%c", &ch );
			board[y][x] = ch;
		}
	}
}
int main(void) {
	int n, T;
	char word[11];

	scanf( "%d", &T );
	while(T--){
		init();

		scanf( "%d", &N );
		for( n=0 ; n<N ; n++ ){
			memset( cache, 0, 10*BMAX*BMAX );
			scanf( "%s", word );
			if( find( word, strlen(word) ) )
				printf( "%s YES\n", word );
			else
				printf( "%s NO\n", word );
		}
	}

	return 0;
}

