#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // n is the total number of elements in the height vector
        int n = height.size();
        // Initialize two pointers, left starting from the beginning and right from the end
        int left = 0, right = n - 1;
        // Initialize the result to store the total trapped water
        int res = 0;
        // Initialize maxLeft and maxRight to track the maximum height seen so far from left and right
        int maxLeft = 0, maxRight = 0;

        // Loop until the left pointer is less than or equal to the right pointer
        while(left <= right) {
            // If the current left height is less than or equal to the current right height
            if(height[left] <= height[right]) {
                // If the current left height is greater than or equal to maxLeft,
                // update maxLeft to the current left height
                if(height[left] >= maxLeft) maxLeft = height[left];
                // Otherwise, add the difference between maxLeft and current left height to res
                else res += maxLeft - height[left];
                // Move the left pointer to the right
                left++;
            } else {
                // If the current right height is greater than or equal to maxRight,
                // update maxRight to the current right height
                if(height[right] >= maxRight) maxRight = height[right];
                // Otherwise, add the difference between maxRight and current right height to res
                else res += maxRight - height[right];
                // Move the right pointer to the left
                right--;
            }
        }
        // Return the total trapped water
        return res;
    }
};

int main() {
    Solution solution;
    // Example test case
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    cout << "The trapped rainwater is: " << solution.trap(height) << endl;
    return 0;
}
