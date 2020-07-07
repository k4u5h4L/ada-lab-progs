#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <time.h>

void heapsort(int h[], int n) {
    int i, j, k, v, heap;
    for (i = n/2; i >= 1; i--) {
        k = i;
        v = h[k];
        heap = 0;
        while (heap == 0 && 2 * k <= n) {
            j = 2 * k;
            if (j < n) {
                if (h[j] < h[j + 1])
                    j++;
            }
            if (v >= h[j])
                heap = 1;
            else {
                h[k] = h[j];
                k = j;
            }
            h[k] = v;
        }
    }
}

void maxheap(int h[], int n) {
    int temp, i;
    for (i = n; i >= 1; i--) {
        heapsort(h, i);
        temp = h[1];
        h[1] = h[i];
        h[i] = temp;
    }
}

int main(void) {
    struct timeval tv1, tv2;
    struct rusage r_usage;
    int i, n, a[20];
    printf("Enter the input size\n");
    scanf("%d", &n);
    printf("Enter elements\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    gettimeofday(&tv1, NULL);
    maxheap(a, n);
    gettimeofday(&tv2, NULL);
    printf("Sorted elements\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\nTime taken = %0.2f microseconds\n", (double) (tv2.tv_usec - tv1.tv_usec));
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory consumed = %ld kilobytes\n", r_usage.ru_maxrss);
    
    return 0;
}