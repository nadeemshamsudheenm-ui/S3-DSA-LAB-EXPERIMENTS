/* Experiment 12d: Quick sort (non-recursive, using a stack of indices) */
#include <stdio.h>
#define MAX 100

/* Partition a[left..right] using the last element as pivot */
int partition(int a[], int left, int right) {
    int pivot = a[right], i = left - 1, j, temp;

    for (j = left; j < right; j++) {
        if (a[j] <= pivot) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];                           /* place pivot in its correct position */
    a[i + 1] = a[right];
    a[right] = temp;
    return i + 1;
}

int main() {
    int a[MAX], stack[2 * MAX], top = -1;
    int n, i, left, right, pivot_index;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    stack[++top] = 0;                          /* push left = 0 */
    stack[++top] = n - 1;                      /* push right = n-1 */

    while (top != -1) {
        right = stack[top--];                  /* pop the pair of indices */
        left = stack[top--];

        pivot_index = partition(a, left, right);

        if (pivot_index > left) {              /* subarray to the left of pivot */
            stack[++top] = left;
            stack[++top] = pivot_index - 1;
        }
        if (pivot_index < right) {             /* subarray to the right of pivot */
            stack[++top] = pivot_index + 1;
            stack[++top] = right;
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
