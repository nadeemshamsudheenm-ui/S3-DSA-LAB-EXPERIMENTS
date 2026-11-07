/* Experiment 2: Transpose and addition of sparse matrices
   Triplet representation: row 0 = {rows, cols, number of non-zero}
   Rows 1..n = {row, col, value}, kept in row-major order */
#include <stdio.h>
#define MAX 100

void readSparse(int s[][3], char name) {
    int r, c, i, j, v, k = 1;
    printf("Enter rows and columns of matrix %c: ", name);
    scanf("%d %d", &r, &c);
    printf("Enter the %dx%d matrix:\n", r, c);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            scanf("%d", &v);
            if (v != 0) {
                s[k][0] = i; s[k][1] = j; s[k][2] = v; k++;
            }
        }
    s[0][0] = r; s[0][1] = c; s[0][2] = k - 1;
}

void displayTriplet(int s[][3]) {
    int i;
    printf("Row\tCol\tValue\n");
    for (i = 0; i <= s[0][2]; i++)
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
}

void displayMatrix(int s[][3]) {
    int i, j, k = 1;
    for (i = 0; i < s[0][0]; i++) {
        for (j = 0; j < s[0][1]; j++) {
            if (k <= s[0][2] && s[k][0] == i && s[k][1] == j)
                printf("%d\t", s[k++][2]);
            else
                printf("0\t");
        }
        printf("\n");
    }
}

void transpose(int a[][3], int t[][3]) {
    int col, i, k = 1;
    t[0][0] = a[0][1]; t[0][1] = a[0][0]; t[0][2] = a[0][2];
    for (col = 0; col < a[0][1]; col++)
        for (i = 1; i <= a[0][2]; i++)
            if (a[i][1] == col) {
                t[k][0] = a[i][1];
                t[k][1] = a[i][0];
                t[k][2] = a[i][2];
                k++;
            }
}

int add(int a[][3], int b[][3], int c[][3]) {
    int i = 1, j = 1, k = 1, pa, pb, s;
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) return 0;
    while (i <= a[0][2] && j <= b[0][2]) {
        pa = a[i][0] * a[0][1] + a[i][1];   /* linear position */
        pb = b[j][0] * b[0][1] + b[j][1];
        if (pa < pb) {
            c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2]; k++; i++;
        } else if (pa > pb) {
            c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2]; k++; j++;
        } else {
            s = a[i][2] + b[j][2];
            if (s != 0) { c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = s; k++; }
            i++; j++;
        }
    }
    while (i <= a[0][2]) {
        c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2]; k++; i++;
    }
    while (j <= b[0][2]) {
        c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2]; k++; j++;
    }
    c[0][0] = a[0][0]; c[0][1] = a[0][1]; c[0][2] = k - 1;
    return 1;
}

int main() {
    int a[MAX][3], b[MAX][3], t[MAX][3], c[MAX][3], ch;
    do {
        printf("\n1. Transpose of a sparse matrix\n2. Addition of two sparse matrices\n3. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            readSparse(a, 'A');
            printf("\nTriplet form of A:\n"); displayTriplet(a);
            transpose(a, t);
            printf("\nTriplet form of transpose:\n"); displayTriplet(t);
            printf("\nTranspose matrix:\n"); displayMatrix(t);
            break;
        case 2:
            readSparse(a, 'A');
            readSparse(b, 'B');
            if (add(a, b, c)) {
                printf("\nTriplet form of sum:\n"); displayTriplet(c);
                printf("\nSum matrix:\n"); displayMatrix(c);
            } else
                printf("Addition not possible: orders differ.\n");
            break;
        }
    } while (ch != 3);
    return 0;
}
