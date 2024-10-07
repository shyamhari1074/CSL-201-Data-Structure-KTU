#include <stdio.h>
#include <stdlib.h>

// Define structure for stack node
struct Node {
    int Data; // Data field to store the stack element
    struct Node* next; // Pointer to the next node
};

struct Node* head = NULL; // Initialize the head pointer to NULL (empty stack)

// Function to create a new node with the given data
struct Node* newnode(int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for a new node
    ptr->Data = data; // Set the data
    ptr->next = NULL; // Initialize next to NULL
    return ptr; // Return the new node
}

// Function to check if the stack is empty
int isEmpty(struct Node* head) {
    return head == NULL; // Return true if head is NULL, indicating an empty stack
}

// Function to push an element onto the stack
void push(struct Node** head, int data) {
    struct Node* temp = newnode(data); // Create a new node with the given data
    if (*head == NULL) { // If the stack is empty
        *head = temp; // Set the new node as the head
    } else {
        temp->next = *head; // Link the new node to the current head
        *head = temp; // Update head to the new node
    }
    printf("%d pushed onto stack\n", data); // Print confirmation
}

// Function to pop an element from the stack
void pop(struct Node** head) {
    if (isEmpty(*head)) { // Check if the stack is empty
        printf("Stack underflow\n"); // Print underflow message if empty
    } else {
        struct Node* temp = *head; // Temporarily store the current head
        printf("%d popped from stack\n", (*head)->Data); // Print the data of the node being popped
        *head = (*head)->next; // Update the head to the next node
        free(temp); // Free the memory of the popped node
    }
}

// Function to display all elements in the stack
void display(struct Node* head) {
    if (isEmpty(head)) { // Check if the stack is empty
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        // Traverse the linked list and print each element
        while (head != NULL) { 
            printf("%d->", head->Data);
            head = head->next; // Move to the next node
        }
        printf("NULL\n"); // Indicate the end of the stack
    }
}

int main() {
    int choice, data;

    do {
        // Display menu options
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform actions based on user's choice
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&head, data); // Push data onto the stack
                break;

            case 2:
                pop(&head); // Pop element from the stack
                break;

            case 3:
                display(head); // Display the current stack
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n"); // Handle invalid menu input
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0;
}
