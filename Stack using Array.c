#include <stdio.h>

#define MAX_SIZE 3  // Maximum size of the stack

int top = -1;  // Index of the top element in the stack (-1 means stack is empty)
int stack[MAX_SIZE];  // Array to store stack elements

// Function to push an element onto the stack
void push(int x) {
    if(top == MAX_SIZE - 1) {  // Check if the stack is full
        printf("Stack is full. Overflow condition!\n");
        return;  // Return if overflow occurs
    }
    stack[++top] = x;  // Increment top and add element to stack
}

// Function to pop an element from the stack
int pop() {
    if(top == -1) {  // Check if the stack is empty
        printf("Stack is empty. Underflow condition!\n");
        return -1;  // Return -1 if underflow occurs
    }
    return stack[top--];  // Return the top element and decrement top
}

// Function to display all elements in the stack
void display() {
    if(top == -1) {  // Check if the stack is empty
        printf("Stack is empty.\n");
        return;  // Return if stack is empty
    }
    printf("Stack elements are: ");
    for(int i = 0; i <= top; i++) {  // Loop to display all elements from bottom to top
        printf("%d ", stack[i]);
    }
    printf("\n");  // Newline after displaying all elements
}

// Main function to drive the program
int main() {
    int choice, x;  // Variables to store user choice and element to push/pop
    while(1) {
        // Display menu options
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Read user choice
        
        // Switch case to perform operations based on user choice
        switch(choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &x);  // Read the element to push
                push(x);  // Call push function
                break;
            case 2:
                x = pop();  // Call pop function
                if(x != -1)  // Check if pop was successful
                    printf("Popped element is: %d\n", x);
                break;
            case 3:
                display();  // Call display function
                break;
            case 4:
                return 0;  // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");  // Handle invalid input
        }
    }
    return 0;  // End of main function
}
