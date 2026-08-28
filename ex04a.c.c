/* EX.NO: 4.2  LINKED LIST IMPLEMENTATION OF QUEUE ADT
   AIM: To write a C program to implement Queue ADT operations using a linked list. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue() {
    int element;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter element to insert: ");
    scanf("%d", &element);
    newNode->data = element;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Element enqueued successfully.\n");
}

void dequeue() {
    if (front == NULL) {
        printf("Error: Queue Underflow.\n");
        return;
    }
    struct Node *temp = front;
    printf("Dequeued element: %d\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements (front to rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nQueue ADT (Linked List) Menu:\n");
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
