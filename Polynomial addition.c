. #include <stdio.h>

struct Term {
    int coefficient;
    int exponent;
};

int main() {
    struct Term P1[10], P2[10], P3[10];
    int n1, n2, n3 = 0;
    int i = 0, j = 0, k = 0;

    // Input for the number of terms in polynomial P1
    printf("Enter the number of terms in polynomial P1: ");
    scanf("%d", &n1);

    // Input for the number of terms in polynomial P2
    printf("Enter the number of terms in polynomial P2: ");
    scanf("%d", &n2);

    // Input terms for polynomial P1
    printf("Enter the terms for polynomial P1 (coefficient and exponent):\n");
    for (i = 0; i < n1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &P1[i].coefficient, &P1[i].exponent);
    }

    // Input terms for polynomial P2
    printf("Enter the terms for polynomial P2 (coefficient and exponent):\n");
    for (i = 0; i < n2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &P2[i].coefficient, &P2[i].exponent);
    }

    i = 0;
    j = 0;

    // Adding the two polynomials
    while (i < n1 && j < n2) {
        if (P1[i].exponent > P2[j].exponent) {
            P3[k] = P1[i];
            i++;
        } else if (P1[i].exponent < P2[j].exponent) {
            P3[k] = P2[j];
            j++;
        } else {
            P3[k].coefficient = P1[i].coefficient + P2[j].coefficient;
            P3[k].exponent = P1[i].exponent;
            i++;
            j++;
            
            // Only add to the result if the coefficient is not zero
            if (P3[k].coefficient == 0) {
                k--; // Decrement k if the term should not be added
            }
        }
        k++;
    }

    // Copy any remaining terms from P1
    while (i < n1) {
        P3[k] = P1[i];
        i++;
        k++;
    }

    // Copy any remaining terms from P2
    while (j < n2) {
        P3[k] = P2[j];
        j++;
        k++;
    }

    n3 = k;

    // Printing the resultant polynomial P3
    printf("Resultant Polynomial (P3): ");
    for (k = 0; k < n3; k++) {
        printf("%dx^%d", P3[k].coefficient, P3[k].exponent);
        if (k < n3 - 1 && P3[k + 1].coefficient >= 0) {
            printf(" + ");
        }
    }
    printf("\n");

    return 0;
}
