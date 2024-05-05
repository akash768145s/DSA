#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        // Single element or peak at the ends of the array
        if (n == 1) return 0; // Single element is inherently a peak
        if (arr[0] > arr[1]) return 0; // Peak at the beginning
        if (arr[n - 1] > arr[n - 2]) return n - 1; // Peak at the end

        // Binary search for peak in the rest of the array
        int low = 1, high = n - 2; // Exclude already checked ends
        while (low <= high) {
            int mid = (low + high) / 2;
            // Current element is greater than both neighbors
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid; // Mid is a peak
            } else if (arr[mid] > arr[mid - 1]) {
                // Peak is on the right half (ascending part)
                low = mid + 1;
            } else {
                // Peak is on the left half (descending part)
                high = mid - 1;
            }
        }
        // Should not reach here if the array always contains a peak
        return -1;
    }
};

// Driver code
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1}; // Example array
    int result = solution.findPeakElement(nums);
    cout << "Peak element is at index: " << result << endl; // Expected: 2 (since arr[2] = 3 is a peak)
    return 0;
}
