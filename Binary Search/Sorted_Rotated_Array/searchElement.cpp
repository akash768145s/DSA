#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    // The search space is between positions low and high.
    while (low <= high) {
        int mid = (low + high) / 2;
        // If the middle element is the target, return its index.
        if (arr[mid] == k) return mid;
        
        // Determine which side of the array is properly sorted.
        if (arr[low] <= arr[mid]) {
            // If the left side is sorted and k is within the range of this side,
            // narrow the search space to the left half.
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            } else {
                // Otherwise, search in the right half.
                low = mid + 1;
            }
        } else {
            // If the right side is sorted and k is within the range of this side,
            // narrow the search space to the right half.
            if (arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;
            } else {
                // Otherwise, search in the left half.
                high = mid - 1;
            }
        }
    }
    // If the element is not found, return -1.
    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();
    int k = 0; // Element to search for.
    int result = search(arr, n, k);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
    return 0;
}
