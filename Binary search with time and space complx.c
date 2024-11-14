#include <stdio.h>
int main() {
    int n, i, key, left, right, mid, space = 0, count = 0;
    space = 8 * sizeof(int); // 8 integers for variables

    // Input the limit of the array
    printf("Enter the limit: "); 
    count++; // for printf
    scanf("%d", &n); 
    count++; // for scanf

    // Create an array of size n and add its space to the space complexity
    int a[n];
    space += n * sizeof(int); // Array size added to space complexity

    // Input elements of the array
    printf("Enter the elements: "); 
    count++; // for printf
    for (i = 0; i < n; i++) {
        count++; // for loop initialization and check
        scanf("%d", &a[i]); 
        count += 2; // for scanf and increment of loop counter
    } 
    count++; // for final check of the loop

    // Input the search key
    printf("Enter the search key: ");
    count += 2; // for printf and scanf
    scanf("%d", &key);

    // Initialize left and right bounds for binary search
    left = 0; 
    count++; // for left assignment
    right = n - 1; 
    count++; // for right assignment

    // Binary Search
    while (left <= right) {
        count++; // for while condition check
        mid = (left + right) / 2; 
        count++; // for mid calculation

        if (key == a[mid]) {
            count++; // for if condition check
            printf("%d element found at position %d\n", key, mid + 1); 
            count++; // for printf
            break; // element found, exit loop
        } else if (key < a[mid]) {
            count++; // for else-if condition check
            right = mid - 1; 
            count++; // for right assignment
        } else if (key > a[mid]) {
            count++; // for else-if condition check
            left = mid + 1; 
            count++; // for left assignment
        }
        count += 2; // for while loop update and additional condition checks
    }

    // Check if element was not found
    if (left > right) {
        count++; // for if condition check
        printf("Element not found.\n"); 
        count++; // for printf
    }
    count++; // for final check of the while loop

    // Output time and space complexity
count+=2 // for printf
    printf("\nThe time complexity is: %d\n", count);
    printf("The space complexity is: %d bytes\n", space);

    return 0;
}
