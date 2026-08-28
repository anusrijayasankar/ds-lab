/* EX.NO: 10.2  IMPLEMENTATION OF BINARY SEARCH
   AIM: To write a C program to implement binary search (array must be sorted). */

#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void bubbleSortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
            }
}

int main() {
    int n, key, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bubbleSortAscending(arr, n); /* ensure the array is sorted */

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);
    if (result != -1)
        printf("Element found at position: %d (in sorted array)\n", result);
    else
        printf("Element not found in the array.\n");

    return 0;
}
