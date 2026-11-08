/* Experiment 12b: Insertion sort */
#include <stdio.h>
#define MAX 100

int main() {
    int a[MAX], n, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i < n; i++) {                  /* start from the second element */
        j = i;
        while (j > 0 && a[j] < a[j - 1]) {     /* current smaller than previous: swap */
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
