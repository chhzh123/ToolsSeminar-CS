// Author: Yucheng Chen

#include<cstdio>

using namespace std ; 

const int N = 101 ; 

char s[N][N] ; 

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n , ans;

int q[N*N][2] ; 

bool Bfs( int x,  int y ) {
	int l = 0 , r = 0 ; 
	q[++r][0] = x , q[r][1] = y ; 
	s[x][y]='#';
	while( l!=r ) {
		++ l ; 
		for( int k=0 ; k<4 ; k++ ) {
			int nx = q[l][0]+dx[k] , ny = q[l][1] + dy[k] ; 
			if( nx && nx<=n && ny && ny <= n ) {
				if( s[nx][ny] == '.' ) {
					++ r ; 
					s[nx][ny]='#';
					q[r][0] = nx , q[r][1] = ny ; 
					if( nx==n && ny==n ) 
						return 1 ; 
				}
			}
		}
	}
	return 0 ; 
} 
int main() {
	freopen("in.txt","r",stdin ) ;
	scanf("%d",&n ) ; 
	for( int i=1 ; i<=n ; i++ ) {
		scanf("%s",s[i]+1 ) ; 
	}
	if( Bfs( 1 , 1 ) ) {
		puts("yes" ) ;
	}
       	else puts("No" ) ; 
}
