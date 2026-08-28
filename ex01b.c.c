/* EX.NO: 1.2  LINKED LIST IMPLEMENTATION OF LIST ADT
   AIM: To write a C program to implement List ADT operations using a singly linked list. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertElement() {
    int element, position, i;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position to insert (0 for beginning): ");
    scanf("%d", &position);
    newNode->data = element;

    if (position == 0 || head == NULL) {
        newNode->next = head;
        head = newNode;
        printf("Element inserted successfully.\n");
        return;
    }

    struct Node *temp = head;
    for (i = 0; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Element inserted successfully.\n");
}

int searchElement() {
    int element, pos = 0;
    printf("Enter element to search: ");
    scanf("%d", &element);
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data == element)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

void deleteElement() {
    int position, i;
    printf("Enter position to delete (0 for first node): ");
    scanf("%d", &position);

    if (head == NULL) {
        printf("Error: List is empty.\n");
        return;
    }

    struct Node *temp = head;
    if (position == 0) {
        head = temp->next;
        free(temp);
        printf("Element deleted successfully.\n");
        return;
    }

    struct Node *prev = NULL;
    for (i = 0; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Invalid position.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Element deleted successfully.\n");
}

void displayList() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, result;
    while (1) {
        printf("\nList ADT (Linked List) Menu:\n");
        printf("1. Insert Element\n2. Search Element\n3. Delete Element\n");
        printf("4. Display List\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertElement(); break;
            case 2:
                result = searchElement();
                if (result != -1)
                    printf("Element found at position: %d\n", result);
                else
                    printf("Element not found in the list.\n");
                break;
            case 3: deleteElement(); break;
            case 4: displayList(); break;
            case 5: return 0;
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
