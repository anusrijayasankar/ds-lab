/* EX.NO: 1.1  ARRAY IMPLEMENTATION OF LIST ADT
   AIM: To write a C program to implement List ADT operations using array. */

#include <stdio.h>
#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

void createList() {
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("List created successfully.\n");
}

void insertElement() {
    int element, position;
    if (size >= MAX_SIZE) {
        printf("Error: List is full.\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position to insert (0 to %d): ", size);
    scanf("%d", &position);
    if (position < 0 || position > size) {
        printf("Error: Invalid position.\n");
        return;
    }
    for (int i = size; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = element;
    size++;
    printf("Element inserted successfully.\n");
}

int searchElement() {
    int element;
    printf("Enter element to search: ");
    scanf("%d", &element);
    for (int i = 0; i < size; i++)
        if (arr[i] == element)
            return i;
    return -1;
}

void deleteElement() {
    int position;
    printf("Enter position to delete (0 to %d): ", size - 1);
    scanf("%d", &position);
    if (position < 0 || position >= size) {
        printf("Error: Invalid position.\n");
        return;
    }
    for (int i = position; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
    printf("Element deleted successfully.\n");
}

void displayList() {
    if (size == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, result;
    while (1) {
        printf("\nList ADT (Array) Menu:\n");
        printf("1. Create List\n2. Insert Element\n3. Search Element\n");
        printf("4. Delete Element\n5. Display List\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createList(); break;
            case 2: insertElement(); break;
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
