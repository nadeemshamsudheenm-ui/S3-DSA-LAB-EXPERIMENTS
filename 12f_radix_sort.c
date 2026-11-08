/* Experiment 12f: Radix sort (non-negative integers) */
#include <stdio.h>
#define MAX 100

void radixSort(int ARR[], int N) {
    int bucket[10][MAX], count[10];
    int LARGE, NOP, PASS, I, J, K, DIGIT, divisor = 1, temp;

    LARGE = ARR[0];                            /* Step 1: largest number */
    for (I = 1; I < N; I++)
        if (ARR[I] > LARGE)
            LARGE = ARR[I];

    NOP = 0;                                   /* Step 2: number of digits in LARGE */
    temp = LARGE;
    do {
        NOP++;
        temp = temp / 10;
    } while (temp > 0);

    for (PASS = 0; PASS <= NOP - 1; PASS++) {  /* Steps 3-4 */
        for (K = 0; K < 10; K++)               /* Step 5: initialise buckets */
            count[K] = 0;

        for (I = 0; I < N; I++) {              /* Steps 6-9 (loop runs for all N elements) */
            DIGIT = (ARR[I] / divisor) % 10;
            bucket[DIGIT][count[DIGIT]] = ARR[I];
            count[DIGIT]++;
        }

        I = 0;                                 /* Step 10: collect numbers from buckets */
        for (K = 0; K < 10; K++)
            for (J = 0; J < count[K]; J++)
                ARR[I++] = bucket[K][J];

        divisor = divisor * 10;
    }
}

int main() {
    int ARR[MAX], N, i;

    printf("Enter the number of elements: ");
    scanf("%d", &N);
    printf("Enter %d non-negative elements:\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &ARR[i]);

    radixSort(ARR, N);

    printf("Sorted array: ");
    for (i = 0; i < N; i++)
        printf("%d ", ARR[i]);
    printf("\n");
    return 0;
}
