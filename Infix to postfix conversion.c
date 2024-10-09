#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *stack;         
int top = -1;
int maxSize;      

// Push an element onto the stack
void push(char x) {
    if (top >= maxSize - 1) {  // Check if the stack is full
        printf("Stack overflow\n");
        exit(1);  // Exit if overflow occurs
    }
    stack[++top] = x;  // Increment top and add element
}

// Pop an element from the stack
char pop() {
    if (top == -1) {  // Check if the stack is empty
        printf("Stack underflow\n");
        exit(1);  // Exit if underflow occurs
    }
    return stack[top--];  // Return the top element and decrement top
}

// Determine the precedence of operators
int precedence(char x) {
    if (x == '+' || x == '-') return 1;  // Low precedence for + and -
    if (x == '*' || x == '/') return 2;  // Higher precedence for * and /
    return 0;  // No precedence for other characters
}

// Convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;  // i for scanning infix, j for building postfix
    for (i = 0; i < strlen(infix); i++) {
        if (infix[i] == ' ') continue;  // Skip spaces in the input

        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];  // Add operand directly to postfix
        } else if (infix[i] == '(') {
            push(infix[i]);  // Push '(' onto the stack
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();  // Pop and add to postfix until '('
            if (top != -1)
                pop();  // Pop the '(' itself
        } else {
            // Pop from stack until we find an operator with less precedence
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();  // Add popped operators to postfix
            push(infix[i]);  // Push the current operator onto the stack
        }
    }
    // Pop and add all remaining operators from the stack
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Evaluate the postfix expression
int evaluatePostfix(char postfix[]) {
    int i, x1, x2;
    top = -1;  // Reset the stack for evaluation

    for (i = 0; i < strlen(postfix); i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');  // Convert char to int and push
        } else if (postfix[i] == ' ') {
            continue;  // Skip spaces
        } else {
            x2 = pop();  // Pop the second operand
            x1 = pop();  // Pop the first operand
            switch (postfix[i]) {  // Perform the corresponding operation
                case '+': push(x1 + x2); break;
                case '-': push(x1 - x2); break;
                case '*': push(x1 * x2); break;
                case '/':
                    if (x2 != 0) {
                        push(x1 / x2);  // Push result of division if valid
                    } else {
                        printf("Error: Division by zero\n");
                        exit(1);  // Exit on division by zero
                    }
                    break;
                default:
                    printf("Error: Invalid character in postfix expression\n");
                    exit(1);  // Exit on invalid operator
            }
        }
    }
    return pop();  // Return the final result from the stack
}

int main() {
    char infix[100], postfix[100];

    // Ask user for the maximum size of the stack
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &maxSize);

    // Allocate memory for the stack based on the user input
    stack = (char *)malloc(maxSize * sizeof(char));  
    if (stack == NULL) {  // Check if memory allocation is successful
        printf("Memory allocation failed\n");
        return 1;  // Return error if memory allocation fails
    }

    while (getchar() != '\n');  // Clear input buffer

    // Get the infix expression from the user
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';  // Remove the trailing newline

    // Convert infix to postfix and print the result
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    // Evaluate the postfix expression and print the result
    printf("Result: %d\n", evaluatePostfix(postfix));
    
    free(stack);  // Free the allocated memory for the stack
    return 0;
}
