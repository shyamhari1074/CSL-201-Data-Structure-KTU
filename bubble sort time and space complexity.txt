#include <stdio.h>

int main() {
    int i, j, temp, n, space = 0, count = 0;
    
    // Calculate initial space for 7 variables of int type and 1 int for n
    space = 7 * sizeof(int);

    // Input the limit of the array
    printf("Enter the limit: "); 
    count++; // Increment count for printf
    scanf("%d", &n); 
    count++; // Increment count for scanf

    // Create an array of size n and add its space to the space complexity
    int a[n];
    space += n * sizeof(int);

    // Input elements of the array
    printf("Enter the elements of the array: "); 
    count++; // Increment count for printf
    for (i = 0; i < n; i++) { 
        count++; // Increment count for the for loop
        scanf("%d", &a[i]); 
        count++; // Increment count for scanf
    } 
    count++; // For the last iteration of the for loop

    // Bubble sort algorithm
    for (i = 0; i < n - 1; i++) { 
        count++; // Increment count for the outer for loop
        for (j = 0; j < n - i - 1; j++) { 
            count++; // Increment count for the inner for loop
            if (a[j] > a[j + 1]) { 
                count++; // Increment count for the if condition
                // Swap elements a[j] and a[j + 1]
                temp = a[j]; 
                count++; // Increment count for temp assignment
                a[j] = a[j + 1]; 
                count++; // Increment count for assignment
                a[j + 1] = temp; 
                count++; // Increment count for assignment
            } 
            count++; // For the inner loop condition check
        } 
        count++; // For the outer loop condition check
    } 
    count++; // For the last iteration of the outer loop

    // Print the sorted array
    printf("The sorted array is: "); 
    count++; // Increment count for printf
    for (i = 0; i < n; i++) { 
        count++; // Increment count for the for loop
        printf("%d ", a[i]); 
        count++; // Increment count for printf
    } 
    count++; // For the last iteration of the for loop
    printf("\n");

    // Print space and time complexities
    printf("The space complexity is: %d bytes\n", space); 
    count += 2; // Increment count for printf
    printf("The time complexity is: %d\n", count);

    return 0;
}
