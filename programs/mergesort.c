#include <stdio.h>

int a[20], b[20];

void merging(int low, int mid, int high) {
    int l1, l2, i;
    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if (a[l1] <= a[l2]) {
            b[i] = a[l1++];
        }
        else {
            b[i] = a[l2++];
        }
    }
    while (l1 <= mid)
        b[i++] = a[l1++];
    while (l2 <= high)
        b[i++] = a[l2++];
    for (i = 0; i <= high; i++)
        a[i] = b[i];        
}

void mergesort(int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merging(low, mid, high);
    }
}

int main(void) {
    int i, n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergesort(0, n - 1);
    printf("Sorted:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}