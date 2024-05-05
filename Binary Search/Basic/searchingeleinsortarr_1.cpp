#include <stdio.h>

int searchInSorted(int arr[], int N, int K) {
    int left = 0;
    int right = N - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if K is present at mid
        if (arr[mid] == K) {
            return 1; // K found
        }

        // If K greater, ignore left half
        if (arr[mid] < K) {
            left = mid + 1;
        }
        // If K is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    // If we reach here, then the element was not present
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 6;
    int result = searchInSorted(arr, N, K);

    if (result == 1) {
        printf("Output: 1\nExplanation: Since, %d is present in the array, output is 1.\n", K);
    } else {
        printf("Output: -1\nExplanation: Since, %d is not present in the array, output is -1.\n", K);
    }

    return 0;
}
