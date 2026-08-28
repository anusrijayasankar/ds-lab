/* EX.NO: 9  IMPLEMENTATION OF PRIORITY QUEUES
   AIM: To write a C program to implement priority queues using a min-heap. */

#include <stdio.h>
#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert() {
    int element;
    if (size >= MAX_SIZE) {
        printf("Error: Heap is full.\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &element);

    int i = size++;
    heap[i] = element;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("Element inserted successfully.\n");
}

void heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

void deleteMin() {
    if (size == 0) {
        printf("Error: Heap is empty.\n");
        return;
    }
    printf("Deleted minimum element: %d\n", heap[0]);
    heap[0] = heap[--size];
    heapify(0);
}

void display() {
    if (size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Heap elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nPriority Queue (Min-Heap) Menu:\n");
        printf("1. Insert\n2. Delete Min\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: deleteMin(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
