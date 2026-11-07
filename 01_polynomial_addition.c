/* Experiment 1: Polynomial addition using arrays
   Index of the array = exponent, value = coefficient */
#include <stdio.h>
#define MAX 50

void readPoly(int p[], int *deg, char name) {
    int i;
    printf("Enter degree of polynomial %c: ", name);
    scanf("%d", deg);
    for (i = 0; i < MAX; i++) p[i] = 0;
    for (i = *deg; i >= 0; i--) {
        printf("  Coefficient of x^%d: ", i);
        scanf("%d", &p[i]);
    }
}

void display(int p[], int deg) {
    int i, first = 1;
    for (i = deg; i >= 0; i--) {
        if (p[i] == 0) continue;
        if (!first && p[i] > 0) printf(" + ");
        else if (p[i] < 0) printf(" - ");
        if (p[i] < 0 ? -p[i] != 1 || i == 0 : p[i] != 1 || i == 0)
            printf("%d", p[i] < 0 ? -p[i] : p[i]);
        if (i > 1) printf("x^%d", i);
        else if (i == 1) printf("x");
        first = 0;
    }
    if (first) printf("0");
    printf("\n");
}

int main() {
    int a[MAX], b[MAX], c[MAX], da, db, dc, i;

    readPoly(a, &da, 'A');
    readPoly(b, &db, 'B');

    dc = (da > db) ? da : db;
    for (i = 0; i <= dc; i++) c[i] = a[i] + b[i];

    printf("\nA(x) = "); display(a, da);
    printf("B(x) = "); display(b, db);
    printf("Sum  = "); display(c, dc);
    return 0;
}
