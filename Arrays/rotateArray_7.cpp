#include <iostream>
using namespace std;

// Function to rotate an array to the right by one position
void rotate(int arr[], int n)
{
    // Store the last element of the array in 'x'
    int x = arr[n - 1];

    // Loop from the end of the array to the beginning
    // Note: This loop starts from the second to last element (at index n-1) and moves each element to the right
    for (int i = n - 1; i > 0; i--)
    {
        // Shift the current element to the right by copying the previous element into the current position
        arr[i] = arr[i - 1];
    }

    // Place the originally last element (stored in 'x') at the beginning of the array
    arr[0] = x;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Before rotation
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Rotate the array
    rotate(arr, n);

    // After rotation
    cout << "Array after rotation: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
