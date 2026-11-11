#include <stdio.h>
struct poly {
    int coef; // Coefficient of the term
    int expo; // Exponent of the term
};

int main() {
    // Declare arrays to store two input polynomials and the resulting polynomial
    struct poly poly1[20], poly2[20], polyresult[40];
    int i, j, k, n1, n2;
     // Step 1: Read the number of terms for both polynomials
    printf("Enter the number of terms do you want in poly 1 and 2: ");
    scanf("%d%d", &n1, &n2);
       // Step 2: Read the first polynomial in descending order of exponents
    printf("Enter the polynomial 1 in descending order (coef expo):\n");
    for(i = 0; i < n1; i++) {
        scanf("%d%d", &poly1[i].coef, &poly1[i].expo);
    }
       // Step 3: Read the second polynomial in descending order of exponents
    printf("Enter the polynomial 2 in descending order (coef expo):\n");
    for(j = 0; j < n2; j++) {
        scanf("%d%d", &poly2[j].coef, &poly2[j].expo);
    }
       // Step 4: Merge the two polynomials based on their exponents
    i = 0, j = 0, k = 0;   
    while(i < n1 && j < n2) {
        if(poly1[i].expo == poly2[j].expo) {
            // Case A: Exponents are equal, add coefficients together
            polyresult[k].coef = poly1[i].coef + poly2[j].coef;
            polyresult[k].expo = poly1[i].expo;
            k++;
            i++;
            j++;
        }
        else if(poly1[i].expo > poly2[j].expo) {
            // Case B: Polynomial 1 exponent is larger, copy it to the result
            polyresult[k].coef = poly1[i].coef;
            polyresult[k].expo = poly1[i].expo;
            i++;
            k++;
        }
        else {
            // Case C: Polynomial 2 exponent is larger, copy it to the result
            polyresult[k].coef = poly2[j].coef;
            polyresult[k].expo = poly2[j].expo;
            j++;
            k++;
        }
    }
        // Step 5: Copy any remaining terms from polynomial 1 (if any)
    while(i < n1) {
       polyresult[k] = poly1[i];
       i++;
       k++;
    }
    // Step 6: Copy any remaining terms from polynomial 2 (if any)
    while(j < n2) {
       polyresult[k] = poly2[j];
       j++;
       k++;
    }
    // Step 7: Print the final resultant polynomial
    printf("Resultant polynomial: ");
    for(i = 0; i < k; i++) {
        printf("%dx^%d", polyresult[i].coef, polyresult[i].expo);
        // Print '+' between terms, but not after the last term
        if(i < k - 1) {
            printf(" + ");
        }
    }
    printf("\n"); 
    return 0;
}
