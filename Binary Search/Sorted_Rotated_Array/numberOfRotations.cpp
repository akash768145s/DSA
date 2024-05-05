#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

int findKRotation(int arr[], int n) {
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if the current range is sorted
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }
        
        // If the left part is sorted
        if (arr[low] <= arr[mid]) {
            // Update the minimum and its index if necessary
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            // The minimum must be in the right part
            low = mid + 1;
        } else { // Right part is sorted
            // Update the minimum and its index if found a new minimum
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }
            // The minimum must be in the left part
            high = mid - 1;
        }
    }
    return index;
}

// Driver code to test the findKRotation function
int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = findKRotation(arr, n);
    cout << "The array is rotated " << k << " times." << endl;
    return 0;
}
