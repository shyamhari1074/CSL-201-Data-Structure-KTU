#include <stdio.h>

int main() {
    int sp[10][10], tr[10][3]; // Declare the sparse matrix and triplet matrix
    int i, j, k = 1, r, c; // Variables for iteration and matrix dimensions

    // Input the number of rows in the sparse matrix
    printf("Enter the number of rows in the sparse matrix: ");
    scanf("%d", &r);

    // Input the number of columns in the sparse matrix
    printf("Enter the number of columns in the sparse matrix: ");
    scanf("%d", &c);

    // Input the elements of the sparse matrix
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &sp[i][j]);
        }
    }

    // Display the sparse matrix
    printf("The sparse matrix is:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", sp[i][j]);
        }
        printf("\n");
    }

    // Convert the sparse matrix to its triplet representation
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (sp[i][j] != 0) { // If the element is non-zero
                tr[k][0] = i;      // Store row index
                tr[k][1] = j;      // Store column index
                tr[k][2] = sp[i][j]; // Store the non-zero element
                k++;
            }
        }
    }

    // First row of the triplet matrix contains the dimensions and number of non-zero elements
    tr[0][0] = r;      // Number of rows
    tr[0][1] = c;      // Number of columns
    tr[0][2] = k - 1;  // Number of non-zero elements

    // Display the triplet representation
    printf("The triplet representation is:\n");
    for (i = 0; i < k; i++) { // Loop through each triplet
        for (j = 0; j < 3; j++) {
            printf("%d\t", tr[i][j]); // Print each value of the triplet
        }
        printf("\n");
    }

    return 0;
}
