/* Experiment 2: Sparse matrix - tuple form, display, transpose and addition */
#include <stdio.h>
#define MAX 50

int spmatrix[MAX][3];
int transposematrix[MAX][3];

/* Case 1: find tuple form */
void findTupleForm() {
    int row, col, i, j, x, k = 1;      /* k starts at 1; row 0 holds meta-info */

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    printf("Enter the %d x %d matrix elements:\n", row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &x);
            if (x != 0) {
                spmatrix[k][0] = i;
                spmatrix[k][1] = j;
                spmatrix[k][2] = x;
                k++;
            }
        }
    }
    spmatrix[0][0] = row;
    spmatrix[0][1] = col;
    spmatrix[0][2] = k - 1;
}

/* Display any matrix in tuple form */
void display(int m[][3]) {
    int i;
    printf("Row\tCol\tValue\n");
    for (i = 0; i <= m[0][2]; i++)
        printf("%d\t%d\t%d\n", m[i][0], m[i][1], m[i][2]);
}

/* Case 3: find transpose */
void findTranspose() {
    int i, j, k = 1;

    transposematrix[0][0] = spmatrix[0][1];
    transposematrix[0][1] = spmatrix[0][0];
    transposematrix[0][2] = spmatrix[0][2];

    for (i = 0; i < spmatrix[0][1]; i++) {          /* each column i */
        for (j = 1; j <= spmatrix[0][2]; j++) {
            if (spmatrix[j][1] == i) {
                transposematrix[k][0] = spmatrix[j][1];   /* swap row and col */
                transposematrix[k][1] = spmatrix[j][0];
                transposematrix[k][2] = spmatrix[j][2];
                k++;
            }
        }
    }
    printf("Transpose in tuple form:\n");
    display(transposematrix);
}

/* Case 4: add two sparse matrices (entered in tuple form) */
void addSparse() {
    int a[MAX][3], b[MAX][3], c[MAX][3];
    int i = 1, j = 1, k = 1, t;

    printf("Enter rows, columns and non-zero terms of matrix A: ");
    scanf("%d %d %d", &a[0][0], &a[0][1], &a[0][2]);
    printf("Enter rows, columns and non-zero terms of matrix B: ");
    scanf("%d %d %d", &b[0][0], &b[0][1], &b[0][2]);

    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        printf("Error: dimensions differ, addition not possible\n");
        return;
    }

    printf("Enter triplets (row col value) of A in row-wise order:\n");
    for (t = 1; t <= a[0][2]; t++)
        scanf("%d %d %d", &a[t][0], &a[t][1], &a[t][2]);
    printf("Enter triplets (row col value) of B in row-wise order:\n");
    for (t = 1; t <= b[0][2]; t++)
        scanf("%d %d %d", &b[t][0], &b[t][1], &b[t][2]);

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {        /* same position */
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
        else if (a[i][0] < b[j][0] ||
                (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {   /* A smaller */
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        }
        else {                                                  /* B smaller */
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++; k++;
        }
    }
    while (i <= a[0][2]) {
        c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2];
        j++; k++;
    }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    c[0][2] = k - 1;

    printf("Resultant matrix in tuple form:\n");
    display(c);
}

int main() {
    int ch;
    do {
        printf("\n1 -- Find Tuple Form\n2 -- Display Sparse Matrix\n"
               "3 -- Find Transpose\n4 -- Add Sparse Matrices\n5 -- Exit\n"
               "Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: findTupleForm(); break;
        case 2: display(spmatrix); break;
        case 3: findTranspose(); break;
        case 4: addSparse(); break;
        case 5: break;
        default: printf("Invalid choice\n");
        }
    } while (ch != 5);
    return 0;
}
