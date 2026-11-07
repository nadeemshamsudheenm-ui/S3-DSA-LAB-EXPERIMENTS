/* Experiment 1: Polynomial addition using arrays of structures */
#include <stdio.h>
#define MAX 20

struct poly {
    int coeff;
    int expo;
};

/* Step 4: read a polynomial (terms in descending order of exponent) */
void readPolynomial(struct poly p[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent of term %d: ", i + 1);
        scanf("%d %d", &p[i].coeff, &p[i].expo);
    }
}

/* Step 5: add two polynomials */
void addPolynomials(struct poly poly1[], int n1, struct poly poly2[], int n2,
                    struct poly polyResult[], int *nResult) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (poly1[i].expo == poly2[j].expo) {
            polyResult[k].coeff = poly1[i].coeff + poly2[j].coeff;
            polyResult[k].expo = poly1[i].expo;
            i++; j++; k++;
        }
        else if (poly1[i].expo > poly2[j].expo) {
            polyResult[k] = poly1[i];
            i++; k++;
        }
        else {
            polyResult[k] = poly2[j];
            j++; k++;
        }
    }

    while (i < n1) {            /* remaining terms of poly1 */
        polyResult[k] = poly1[i];
        i++; k++;
    }
    while (j < n2) {            /* remaining terms of poly2 */
        polyResult[k] = poly2[j];
        j++; k++;
    }

    *nResult = k;
}

/* Step 6: display polynomial */
void displayPolynomial(struct poly p[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%dx^%d", p[i].coeff, p[i].expo);
        if (i < n - 1)
            printf(" + ");
    }
    printf("\n");
}

/* Step 7: main */
int main() {
    struct poly poly1[MAX], poly2[MAX], polyResult[2 * MAX];
    int n1, n2, nResult;

    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &n2);

    printf("\nPolynomial 1 (descending order of exponents):\n");
    readPolynomial(poly1, n1);
    printf("\nPolynomial 2 (descending order of exponents):\n");
    readPolynomial(poly2, n2);

    printf("\nPolynomial 1 = ");
    displayPolynomial(poly1, n1);
    printf("Polynomial 2 = ");
    displayPolynomial(poly2, n2);

    addPolynomials(poly1, n1, poly2, n2, polyResult, &nResult);

    printf("Sum          = ");
    displayPolynomial(polyResult, nResult);
    return 0;
}
