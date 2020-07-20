#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int a[], int first, int last) {
    int i, j, pivot;

    if (first < last) {
        i = first;
        pivot = first;
        j = last;

        while (i < j) {
            while (a[i] <= a[pivot] && i < last)
                i++;
            while (a[j] > a[pivot]) 
                j--;

            if (i < j) {
                swap(a + i, a + j);
            }

            swap(a + pivot, a + j);

            quicksort(a, first, j - 1);
            quicksort(a, j + 1, last);
        }
    }
}

int main() {
    int a[20], i, j, n;

    printf("enter number\n");
    scanf("%d", &n);

    printf("enter elements\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n-1);

    printf("Sorted:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}