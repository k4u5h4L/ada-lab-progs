#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>
#include <sys/time.h>

void warshall(int n, int r[][10]) {
	int i, j, k;
	
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				r[i][j] = r[i][j] || r[i][k] && r[k][j];
			}
		}
	}
}

int main(void) {
	struct timeval tv1,tv2;
	int n, a[10][10];
	// int r[10][10];
	struct rusage r_usage;
	int i, j;
	printf("Enter the no of rows\n");
	scanf("%d", &n);
	printf("Enter the elements of adjacency matrix\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	// printf("test");
	gettimeofday(&tv1, NULL);
	warshall(n, a);
	gettimeofday(&tv2, NULL);
	printf("The result matrix is:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d\t", a[i][j]);
		}
        printf("\n");
	}
	printf("\nTime taken = %0.2f microseconds\n", (double) (tv2.tv_usec - tv1.tv_usec));
	getrusage(RUSAGE_SELF, &r_usage);
	printf("Memory usage: %ld kilobytes\n", r_usage.ru_maxrss);
	return 0;
}