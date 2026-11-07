/* Experiment 12: Sorting algorithms
   a. Bubble  b. Insertion  c. Selection  d. Quick  e. Merge  f. Radix */
#include <stdio.h>
#include <string.h>
#define MAX 100

void display(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

/* a. Bubble sort */
void bubbleSort(int a[], int n) {
    int i, j, t, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                swapped = 1;
            }
        if (!swapped) break;
    }
}

/* b. Insertion sort */
void insertionSort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

/* c. Selection sort */
void selectionSort(int a[], int n) {
    int i, j, min, t;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;
        t = a[i]; a[i] = a[min]; a[min] = t;
    }
}

/* d. Quick sort (Lomuto partition, last element as pivot) */
int partition(int a[], int low, int high) {
    int pivot = a[high], i = low - 1, j, t;
    for (j = low; j < high; j++)
        if (a[j] <= pivot) {
            i++;
            t = a[i]; a[i] = a[j]; a[j] = t;
        }
    t = a[i + 1]; a[i + 1] = a[high]; a[high] = t;
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    int p;
    if (low < high) {
        p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

/* e. Merge sort */
void merge(int a[], int low, int mid, int high) {
    int tmp[MAX], i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
        tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= high) tmp[k++] = a[j++];
    for (i = low, k = 0; i <= high; i++, k++) a[i] = tmp[k];
}

void mergeSort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

/* f. Radix sort (non-negative integers, LSD, counting sort per digit) */
void countingByDigit(int a[], int n, int exp) {
    int out[MAX], count[10] = {0}, i;
    for (i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
    for (i = 1; i < 10; i++) count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        out[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) a[i] = out[i];
}

void radixSort(int a[], int n) {
    int max = a[0], exp, i;
    for (i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    for (exp = 1; max / exp > 0; exp *= 10)
        countingByDigit(a, n, exp);
}

int main() {
    int orig[MAX], a[MAX], n, i, ch;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements (non-negative if you want to use radix sort):\n", n);
    for (i = 0; i < n; i++) scanf("%d", &orig[i]);

    do {
        memcpy(a, orig, sizeof(int) * n);   /* sort a fresh copy each time */
        printf("\n1.Bubble 2.Insertion 3.Selection 4.Quick 5.Merge 6.Radix 7.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch < 1 || ch > 6) continue;
        switch (ch) {
        case 1: bubbleSort(a, n); break;
        case 2: insertionSort(a, n); break;
        case 3: selectionSort(a, n); break;
        case 4: quickSort(a, 0, n - 1); break;
        case 5: mergeSort(a, 0, n - 1); break;
        case 6: radixSort(a, n); break;
        }
        printf("Sorted array: ");
        display(a, n);
    } while (ch != 7);
    return 0;
}
