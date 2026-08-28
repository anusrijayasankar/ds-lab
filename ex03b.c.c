/* EX.NO: 3.1  ARRAY IMPLEMENTATION OF STACK ADT
   AIM: To write a C program to implement Stack ADT operations using array. */

#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push() {
    int element;
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack Overflow.\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &element);
    stack[++top] = element;
    printf("Element pushed successfully.\n");
}

void pop() {
    if (top == -1) {
        printf("Error: Stack Underflow.\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

void peek() {
    if (top == -1) {
        printf("Error: Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nStack ADT (Array) Menu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
