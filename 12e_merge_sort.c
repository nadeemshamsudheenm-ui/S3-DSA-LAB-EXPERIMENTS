/* Experiment 12e: Merge sort */
#include <stdio.h>
#define MAX 100

void merge(int A[], int left, int mid, int right) {
    int L[MAX], R[MAX];
    int n1 = mid - left + 1, n2 = right - mid;
    int i, j, k;

    for (i = 0; i < n1; i++)                   /* left half  A[left..mid]    */
        L[i] = A[left + i];
    for (j = 0; j < n2; j++)                   /* right half A[mid+1..right] */
        R[j] = A[mid + 1 + j];

    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {                 /* copy the smaller element */
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while (i < n1)                             /* remaining elements */
        A[k++] = L[i++];
    while (j < n2)
        A[k++] = R[j++];
}

void mergeSort(int A[], int left, int right) {
    int mid;
    if (left >= right)                         /* base case */
        return;
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
}

int main() {
    int A[MAX], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    mergeSort(A, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
