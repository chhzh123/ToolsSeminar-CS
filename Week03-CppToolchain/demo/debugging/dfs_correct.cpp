// Author: Yucheng Chen

#include<cstdio>

using namespace std ; 

const int N = 101 ; 

char s[N][N] ; 

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n , ans;

bool Dfs( int x,  int y ) {
	if( x==n&&y==n) return 1 ;
	s[x][y]='#';
	for( int k=0 ; k<4 ; k++ ) {
		int nx = x+dx[k],ny=y+dy[k] ; 
		if( nx>=1 && nx<=n && ny<=n&& ny>=1 ) {
			if( s[nx][ny]=='.' ) {
				if( Dfs( nx,ny ) )
					return 1 ;
			}
		}
	}
	s[x][y]='.';
	return 0 ; 
} 
int main() {
	freopen("in.txt","r",stdin ) ;
	scanf("%d",&n ) ; 
	for( int i=1 ; i<=n ; i++ ) {
		scanf("%s",s[i]+1 ) ; 
	}
	if( Dfs( 1 , 1 ) ) {
		puts("yes" ) ;
	}
       	else puts("No" ) ; 
}
