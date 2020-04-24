#include <stdio.h>
#include <omp.h>
#include <time.h>

#define SIZE 512

int main(){
	int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];
	int m = SIZE, n = SIZE, l = SIZE;

	// initialization
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] = 2*i+j;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < l; ++j)
			b[i][j] = 2*i+j;

	clock_t start, stop;
	// sequential gemm
	start = time(NULL);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			c[i][j] = 0.0;
			for (int k = 0; k < l; ++k)
				c[i][j] += a[i][j] * b[j][k];
		}
	stop = time(NULL);
#ifdef DEBUG
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < l; ++j)
			printf("%d ", c[i][j]);
		printf("\n");
	}
#endif
	printf("Sequential time: %fs\n", (double)(stop-start)/CLOCKS_PER_SEC);
	

	// simple parallel gemm
	start = time(NULL);
	#pragma omp parallel
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			c[i][j] = 0.0;
			for (int k = 0; k < l; ++k)
				c[i][j] += a[i][j] * b[j][k];
		}
	stop = time(NULL);
#ifdef DEBUG
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < l; ++j)
			printf("%d ", c[i][j]);
		printf("\n");
	}
#endif
	printf("Parallel time: %fs\n", (double)(stop-start)/CLOCKS_PER_SEC);
}