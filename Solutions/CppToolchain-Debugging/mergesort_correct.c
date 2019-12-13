/*
 * Author: Yucheng Chen
 *
 * Input n m represent n row, each row is an array of m element.
 *
 * Using MergeSort to sort each array.
 *
 * Sample input
 * 4 3
 * 1 2 3
 * 3 2 1
 * 2 1 3
 * 2 3 1
 *
 * Sample output
 * 1 2 3
 * 1 2 3
 * 1 2 3
 * 1 2 3
 *
 * The program is wrong. Please make it correct.
 *
 */

#include<stdio.h>

int a[1010][1010] , n , m , tmp[1010] ; 

void MergeSort( int row , int l , int r ) {
	int m = l + r >> 1 ; 
	if( l==r ) return ; 
	MergeSort( row, l , m ) ;
	MergeSort( row, m+1 , r ) ; 
	int i = l , j = m+1 , cnt ; 
	for( cnt=1 ; cnt<=r-l+1; cnt++) {
		if( ( i>m || a[row][i]>=a[row][j] ) && j<=r  ) // fix here
			tmp[cnt] = a[row][j++] ; 
		else if( ( j>r || a[row][j]>a[row][i] ) && i<=m ) // fix here
			tmp[cnt] = a[row][i++] ; 
	}
	for( i=l ; i<=r ; i++ ) a[row][i] = tmp[i-l+1] ; 

}

int main() {
	freopen("inc.txt","r",stdin ) ; 
	scanf("%d%d",&n,&m )  ;
	for( int i=1 ; i<=n ; i++ ) {
		for( int j=1 ; j<=m ; j++ ) {
			scanf("%d",&a[i][j] ) ; 
		}
	}
	for( int i=1 ; i<=n ; i++ ) 
		MergeSort( i ,1 , m  ) ; 
	for( int i=1 ;i<=n ;i++ ) 
		for( int j=1 ; j<=m ; j++ )printf("%d%c",a[i][j]," \n"[j==m] ) ;
}