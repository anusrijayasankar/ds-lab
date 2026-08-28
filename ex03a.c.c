/* EX.NO: 3.2  ARRAY IMPLEMENTATION OF QUEUE ADT
   AIM: To write a C program to implement Queue ADT operations using array. */

#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue() {
    int element;
    if (rear == MAX_SIZE - 1) {
        printf("Error: Queue Overflow.\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &element);
    if (front == -1) front = 0;
    queue[++rear] = element;
    printf("Element enqueued successfully.\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Error: Queue Underflow.\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1; /* reset when empty */
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements (front to rear): ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nQueue ADT (Array) Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
