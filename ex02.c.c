/* EX.NO: 2  IMPLEMENTATION OF CIRCULAR LINKED LIST
   AIM: To write a C program to implement a circular linked list and its operations. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL; /* last points to the last node; last->next is the first node */

void insertEnd() {
    int element;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter element to insert: ");
    scanf("%d", &element);
    newNode->data = element;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("Element inserted successfully.\n");
}

void insertBeginning() {
    int element;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter element to insert: ");
    scanf("%d", &element);
    newNode->data = element;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("Element inserted successfully.\n");
}

int searchElement() {
    int element, pos = 0;
    printf("Enter element to search: ");
    scanf("%d", &element);
    if (last == NULL) return -1;

    struct Node *temp = last->next;
    do {
        if (temp->data == element)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != last->next);
    return -1;
}

void deleteElement() {
    int element;
    printf("Enter element to delete: ");
    scanf("%d", &element);

    if (last == NULL) {
        printf("Error: List is empty.\n");
        return;
    }

    struct Node *curr = last->next, *prev = last;
    do {
        if (curr->data == element) {
            if (curr == last && curr->next == last) { /* only one node */
                last = NULL;
            } else {
                prev->next = curr->next;
                if (curr == last)
                    last = prev;
            }
            free(curr);
            printf("Element deleted successfully.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (prev != last);

    printf("Error: Element not found.\n");
}

void displayList() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = last->next;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    int choice, result;
    while (1) {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Insert at End\n2. Insert at Beginning\n3. Search Element\n");
        printf("4. Delete Element\n5. Display List\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertEnd(); break;
            case 2: insertBeginning(); break;
            case 3:
                result = searchElement();
                if (result != -1)
                    printf("Element found at position: %d\n", result);
                else
                    printf("Element not found in the list.\n");
                break;
            case 4: deleteElement(); break;
            case 5: displayList(); break;
            case 6: return 0;
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
