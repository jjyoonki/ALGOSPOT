/*
> L자 블록으로 게임판 덮기 (알159)
   ┌───┬─┬─
   │      │  │
   │  ┌─┘  │
   │  │      │
   ├─┼───┼─
> 입력
   1          T≤30
   3 7        1≤ H,W ≤20
   #.....#    흰칸의 수는 50 이하
   #.....#    (블록의 칸 수는 3)
   ##..### 
> 출력
   덮는 방법의 수
*/
#include <stdio.h>
#include <string.h>
#define NMAX 20

int board[NMAX][NMAX];
int H, W;
int dy[4][3] = { {0,0,1},  {0,0,1},  {0,1,1},  {0, 1,1} };	// ┌ ┐└ ┘
int dx[4][3] = { {0,1,0},  {0,1,1},  {0,0,1},  {0,-1,0} };
int init(){
	int y, x, numb=0;
	char ch;

	memset( board, 0, NMAX*NMAX*sizeof(int) );
	scanf( "%d %d", &H, &W );
	for( y=0 ; y<H ; y++ ){
		for( x=0 ; x<W ; x++ ){
			scanf( "%c", &ch );
			while( ch==' ' || ch=='\n' )
				scanf( "%c", &ch );
			if( ch=='#' )
				board[y][x] = 1;
			else
				numb++;
		}
	}
	return( numb%3 );
}
// b0번째 bar를 배치할 수 있는가?
int canPlace( int y0, int x0, int b0 ){
	int n, y, x;
	for( n=0 ; n<3 ; n++ ){
		y = y0 + dy[b0][n];
		x = x0 + dx[b0][n];
		if( y<0 || H<=y || x<0 || W<=x || board[y][x] )
			return(0);
	}
	return(1);
}
void barPlace( int y0, int x0, int b0, int s ){
	int y, x, n;
	for( n=0 ; n<3 ; n++ ){
		y = y0 + dy[b0][n];
		x = x0 + dx[b0][n];
		board[y][x] += s;
	}
	return;
}
int findEmptyPos( int *y0, int *x0 ){
	int y, x;
	for( y=*y0 ; y<H ; y++ ){
		for( x=0 ; x<W ; x++ ){
			if( !board[y][x] ){
				*y0 = y;
				*x0 = x;
				return(1);
			}
		}
	}
	return(0);
}
int fillBar( int y0, int x0 ){
	int y, x, b, num;		// 방법의 수
	if( !findEmptyPos(&y0,&x0) )
		return(1);

	num = 0;
	for( b=0 ; b<4 ; b++ ){
		if( canPlace( y0, x0, b ) ){
			barPlace( y0, x0, b, 1 );
			num += fillBar( y0, x0 );
			barPlace( y0, x0, b, -1 );
		}
	}
	return(num);
}
int main(void) {
	int T, num, y0=0, x0=0;
	scanf( "%d", &T );
	while(T--){
		if( init() )
			num = 0;
		else
			num = fillBar(0,0);

		printf( "%d\n", num );
	}
	return 0;
}
