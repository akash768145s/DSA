#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // If the element at mid is greater than the element at r, 
            // it means the smallest value is to the right of mid.
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                // Otherwise, the smallest value is to the left of mid (including mid).
                r = mid;
            }
        }
        // At the end of the loop, l and r converge to the minimum element's index.
        return nums[r];
    }
};

// Driver code to test the above Solution class
int main() {
    vector<int> nums = {3, 4, 5, 1, 2}; // Example of a rotated sorted array
    Solution sol;

    // Finding the minimum element using the findMin method
    int minElement = sol.findMin(nums);

    // Printing the minimum element
    cout << "The minimum element in the rotated sorted array is: " << minElement << endl;

    return 0;
}
