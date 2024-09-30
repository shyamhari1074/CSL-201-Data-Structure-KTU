#include <stdio.h>

int main() {
    int i, j, n, temp, min, count = 0, space = 0;
    
    // Calculate initial space complexity: 7 integers used
    space = 7 * sizeof(int);

    // Input limit of the array
    printf("Enter the limit of the array: ");
    count++;
    scanf("%d", &n); 
    count++;
    
    // Create an array with size n
    int a[n];
    // Add the space required for the array to the space complexity
    space += n * sizeof(int);

    // Input elements of the array
    printf("Enter the elements of the array: ");
    count++;
    for (i = 0; i < n; i++) {
        count++;
        scanf("%d", &a[i]); 
        count++;
    } 
    count++;

    // Selection sort algorithm
    for (i = 0; i < n - 1; i++) {
        count++;
        min = i; 
        count++;
        for (j = i + 1; j < n; j++) {
            count++;
            if (a[j] < a[min]) {
                count++;
                min = j; 
                count++;
            }
        }
        // Swap only if the minimum element is not at the current position
        if (i != min) {
            count++;
            temp = a[i]; 
            count++;
            a[i] = a[min]; 
            count++;
            a[min] = temp; 
            count++;
        }
    }
    count++; // For final check in outer loop

    // Print the sorted array
    printf("The sorted array is: "); 
    count++;
    for (i = 0; i < n; i++) {
        count++;
        printf("%d ", a[i]); 
        count++;
    } 
    count++;
    printf("\n");

    // Print the space and time complexity
    printf("The space complexity is: %d bytes\n", space); 
    count+=2;
    printf("The time complexity is: %d\n", count);

    return 0;
}
