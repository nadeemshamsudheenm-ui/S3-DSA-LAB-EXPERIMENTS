#include <stdio.h>

#define MAX 25

void quicksort(int a[], int first, int last) {
    if (first >= last) return;

    // Use the middle element as pivot (avoids worst case on sorted input)
    int mid = first + (last - first) / 2;
    int temp = a[first];
        a[first] = a[mid];
        a[mid] = temp;

    int pivot = first, i = first, j = last;
    while (i < j) {
        while (a[i] <= a[pivot] && i < last) i++;
        while (a[j] > a[pivot]) j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[pivot]; 
    a[pivot] = a[j];
    a[j] = temp;

    quicksort(a, first, j - 1);
    quicksort(a, j + 1, last);
}

int main(void) {
    int number[MAX], count;

    printf("How many elements are you going to enter? (max %d): ", MAX);
    if (scanf("%d", &count) != 1 || count < 1 || count > MAX) {
        printf("Invalid count.\n");
        return 1;
    }

    printf("Enter %d elements: ", count);
    for (int i = 0; i < count; i++) {
        if (scanf("%d", &number[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    quicksort(number, 0, count - 1);

    printf("Sorted elements:");
    for (int i = 0; i < count; i++)
        printf(" %d", number[i]);
        printf("\n");
    return 0;
}
