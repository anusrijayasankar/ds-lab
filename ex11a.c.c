/* EX.NO: 11.2  OPEN ADDRESSING
   AIM: To write a C program to implement hashing using linear probing (open addressing). */

#include <stdio.h>
#include <limits.h>
#define TABLE_SIZE 10
#define EMPTY INT_MIN

int table[TABLE_SIZE];

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = EMPTY;
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert() {
    int key, index, i;
    printf("Enter key to insert: ");
    scanf("%d", &key);
    index = hashFunction(key);

    for (i = 0; i < TABLE_SIZE; i++) {
        int probe = (index + i) % TABLE_SIZE;
        if (table[probe] == EMPTY) {
            table[probe] = key;
            printf("Key inserted at index %d.\n", probe);
            return;
        }
    }
    printf("Error: Hash table is full.\n");
}

void search() {
    int key, index, i;
    printf("Enter key to search: ");
    scanf("%d", &key);
    index = hashFunction(key);

    for (i = 0; i < TABLE_SIZE; i++) {
        int probe = (index + i) % TABLE_SIZE;
        if (table[probe] == EMPTY) {
            printf("Key not found.\n");
            return;
        }
        if (table[probe] == key) {
            printf("Key found at index %d.\n", probe);
            return;
        }
    }
    printf("Key not found.\n");
}

void deleteKey() {
    int key, index, i;
    printf("Enter key to delete: ");
    scanf("%d", &key);
    index = hashFunction(key);

    for (i = 0; i < TABLE_SIZE; i++) {
        int probe = (index + i) % TABLE_SIZE;
        if (table[probe] == EMPTY) {
            printf("Key not found.\n");
            return;
        }
        if (table[probe] == key) {
            table[probe] = EMPTY;
            printf("Key deleted successfully.\n");
            return;
        }
    }
    printf("Key not found.\n");
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == EMPTY)
            printf("[%d]: empty\n", i);
        else
            printf("[%d]: %d\n", i, table[i]);
    }
}

int main() {
    int choice;
    initTable();
    while (1) {
        printf("\nHashing (Open Addressing - Linear Probing) Menu:\n");
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
