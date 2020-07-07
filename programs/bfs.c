#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <sys/resource.h>

int a[50][50], q[50], f = 1, r = -1, visited[50];

int bfs(int n) {
    int i, j;
    int v = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[v][j] && !visited[i]) {
                q[++r] = j;
            }
            if (f <= r) {
                visited[q[f]] = 1;
                printf("%d  ", f++);
            }
        }
    }
    printf("\n");
}

int main(void) {
    struct timeval tv1, tv2;
    int i, j, n;
    struct rusage r_usage;
    
    printf("Enter row size\n");
    scanf("%d", &n);
    
    printf("Enter the matrix elements\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    gettimeofday(&tv1, NULL);
    bfs(n);
    gettimeofday(&tv2, NULL);

    printf("Time of bfs = %.2f microseconds\n", (double)(tv2.tv_usec - tv1.tv_usec));

    getrusage(RUSAGE_SELF, &r_usage);

    printf("Memory usage %ld kilobytes\n", r_usage.ru_maxrss);

    return 0;
}