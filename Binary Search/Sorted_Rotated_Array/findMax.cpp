#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum element in a rotated sorted array
int findMax(int arr[], int low, int high)
{
    // If the array contains only one element
    if (high == low)
        return arr[low];

    // Calculate the middle index
    int mid = low + (high - low) / 2;

    // Special case to handle when the array's size is 2
    // and the first element is the maximum
    if (mid == 0 && arr[mid] > arr[mid + 1])
    {
        return arr[mid];
    }

    // Check if mid element is greater than its next element
    // and also ensure it's greater than its previous element
    // This means mid is the maximum element
    if (mid < high && arr[mid + 1] < arr[mid] && mid > 0 && arr[mid] > arr[mid - 1])
    {
        return arr[mid];
    }

    // Decide the search space, it's divided based on the property of the rotated sorted array.
    // If the element at the start of the array is greater than the mid element,
    // it means the maximum element is in the left half
    if (arr[low] > arr[mid])
    {
        return findMax(arr, low, mid - 1);
    }
    // Otherwise, the maximum element is in the right half
    else
    {
        return findMax(arr, mid + 1, high);
    }
}

// Driver code to test the above function
int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Finding and printing the maximum element using findMax function
    cout << findMax(arr, 0, n - 1);

    return 0;
}
