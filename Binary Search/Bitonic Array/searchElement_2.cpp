#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int> &A, int B);
};

int Solution::solve(vector<int> &A, int B) {
    int low = 0, high = A.size() - 1; // Initialize pointers to start and end of the array.
    
    while (low <= high) { // Continue searching while the search space is valid.
        int mid = low + (high - low) / 2; // Find the middle element to prevent overflow.
        
        if (A[mid] == B) return mid; // If the middle element is the target, return its index.
        
        // Determine which part of the array is sorted.
        if (A[low] <= A[mid]) {
            // If the left side is sorted...
            if (A[low] <= B && B < A[mid]) {
                // And the target is within the range of the sorted left side, focus on that half.
                high = mid - 1;
            } else {
                // Otherwise, the target must be in the right half.
                low = mid + 1;
            }
        } else {
            // If the right side is sorted...
            if (A[mid] < B && B <= A[high]) {
                // And the target is within the range of the sorted right side, focus on that half.
                low = mid + 1;
            } else {
                // Otherwise, the target must be in the left half.
                high = mid - 1;
            }
        }
    }
    
    return -1; // If the loop exits without returning, B is not in the array.
}

int main() {
    Solution solution;
    vector<int> A = {4, 5, 6, 7, 0, 1, 2}; // Example rotated sorted array
    int B = 0; // Target value to find
    int index = solution.solve(A, B); // Search for the target
    cout << "Index of " << B << " in the array is: " << index << endl; // Print the result
    return 0;
}
