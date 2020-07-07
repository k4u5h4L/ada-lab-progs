#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>
#include <sys/time.h>

void swap(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int a[], int first, int last) {
    int i, j, pivot;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (a[i] <= a[pivot] && i < last)
                i++;
            while (a[j] > a[pivot])
                j--;

            if (i < j)
                swap(a + i, a + j);
        }

        swap(a + pivot, a + j);

        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}

int main(void) {
	struct timeval tv1,tv2;
	int n, a[20];
	struct rusage r_usage;
	int i;
    
	printf("Enter the no of elements\n");
	scanf("%d", &n);
    
	printf("Enter the elements of the array\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	gettimeofday(&tv1, NULL);
	quicksort(a, 0, n - 1);
	gettimeofday(&tv2, NULL);

	printf("Sorted array:\n");
	for (i = 0; i < n; i++) {		
		printf("%d\t", a[i]);
	}
    printf("\n");

	printf("\nTime taken = %0.2f microseconds\n", (double) (tv2.tv_usec - tv1.tv_usec));

	getrusage(RUSAGE_SELF, &r_usage);
	printf("Memory usage: %ld kilobytes\n", r_usage.ru_maxrss);

	return 0;
}