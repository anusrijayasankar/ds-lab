/* EX.NO: 11.1  IMPLEMENTATION OF HASHING WITH SEPARATE CHAINING
   AIM: To write a C program to implement hashing using separate chaining. */

#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

struct Node {
    int key;
    struct Node *next;
};

struct Node *table[TABLE_SIZE] = {NULL};

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert() {
    int key, index;
    printf("Enter key to insert: ");
    scanf("%d", &key);
    index = hashFunction(key);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = table[index];
    table[index] = newNode;
    printf("Key inserted at index %d.\n", index);
}

void search() {
    int key, index;
    printf("Enter key to search: ");
    scanf("%d", &key);
    index = hashFunction(key);

    struct Node *temp = table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            printf("Key found at index %d.\n", index);
            return;
        }
        temp = temp->next;
    }
    printf("Key not found.\n");
}

void deleteKey() {
    int key, index;
    printf("Enter key to delete: ");
    scanf("%d", &key);
    index = hashFunction(key);

    struct Node *temp = table[index], *prev = NULL;
    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }
    if (prev == NULL)
        table[index] = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("Key deleted successfully.\n");
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        struct Node *temp = table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nHashing (Separate Chaining) Menu:\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: deleteKey(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
