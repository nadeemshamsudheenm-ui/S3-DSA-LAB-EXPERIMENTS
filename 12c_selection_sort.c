/* Experiment 12c: Selection sort */
#include <stdio.h>
#define MAX 100

int main() {
    int a[MAX], n, i, j, min, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n - 1; i++) {
        min = i;                               /* assume current element is the minimum */
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;                       /* find minimum in the unsorted part */
        }
        temp = a[i];                           /* swap minimum with current element */
        a[i] = a[min];
        a[min] = temp;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
