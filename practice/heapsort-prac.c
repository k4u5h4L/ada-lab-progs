#include <stdio.h>
#include <stdlib.h>

void maxheap(int h[], int n) {
    int i, j, k, v, heap;

    for (i = n/2; i >= 1; i--) {
        k = i;
        v = h[k];
        heap = 0;

        while (heap == 0 && 2*k <= n) {
            j = 2*k;
            if (j < n) {
                if (h[j] < h[j+1]) {
                    j++;
                }
            }
            if (v >= h[j]) {
                heap = 1;
            }
            else {
                h[k] = h[j];
                k = j;
            }
            h[k] = v;
        }
    }
}

void heapsort(int h[], int n) {
    int i, temp;
    for (i = n; i >= 1; i--) {
        maxheap(h, i);
        temp = h[1];
        h[1] = h[i];
        h[i] = temp;
    }
}

void main() {
    int a[20], i, n;

    printf("enter number of elements\n");
    scanf("%d", &n);

    printf("enter elements\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    heapsort(a, n);

    printf("Sorted:\n");
    for (i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}