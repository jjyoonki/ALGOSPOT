/*
9/10 ����
�־��� ������ ���� �κ� ���� �� ���� �� ���� ����

> �Է�
3                 C (<= 50)
4                 N (<= 500)
1 2 3 4           N���� ���� (1<=100,000)
8
5 4 3 2 1 6 7 8 
8
5 6 7 8 1 2 3 4

> ���
4
4
4
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define NMAX 500

int data[NMAX];
int len[NMAX];
int N;

int lis(){
	int nc;	// current
	int np;	// previous
	int lmax;

	len[0] = 1;
	lmax   = 1;

	for( nc=1 ; nc<N ; nc++ ){
		len[nc] = 1;
		for( np=0 ; np<nc ; np++ ){
			if( data[np]<data[nc] )
				len[nc] = MAX( len[nc], len[np]+1 );
		}
		lmax = MAX( lmax, len[nc] );
	}
	
	return(lmax);
}
void init(){
	int n;

//	memset( data, 0, NMAX*sizeof(int) );
//	memset( len,  0, NMAX*sizeof(int) );

	scanf( "%d", &N );
	for( n=0 ; n<N ; n++ )
		scanf( "%d", &data[n] );
}
int main(void) {
	int T;

	scanf( "%d", &T );
	while(T--){
		init();
		printf( "%d\n", lis() );
	}

	return 0;
}

