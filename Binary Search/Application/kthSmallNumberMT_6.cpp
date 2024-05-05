#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to find the kth smallest number in a sorted matrix of size m x n.
    int findKthNumber(int m, int n, int k)
    {
        // Set the lower bound of the binary search to 1.
        int low = 1;
        // Set the upper bound of the binary search to the maximum possible value, which is m * n.
        int high = m * n;

        // Perform binary search until the lower bound is less than or equal to the upper bound.
        while (low <= high)
        {
            // Calculate the middle element of the range.
            int mid = (low + high) / 2;
            // Count the number of elements less than or equal to mid in the matrix.
            if (countElementsLessThanK(mid, m, n) < k)
            {
                // If the count is less than k, update the lower bound to mid + 1.
                low = mid + 1;
            }
            else
            {
                // If the count is greater than or equal to k, update the upper bound to mid - 1.
                high = mid - 1;
            }
        }
        // Return the lower bound which represents the kth smallest element.
        return low;
    }

    // Function to count the number of elements less than or equal to el in the matrix.
    int countElementsLessThanK(int el, int m, int n)
    {
        // Initialize a variable to store the count.
        int count = 0;
        // Iterate through each row of the matrix.
        for (int i = 1; i <= m; i++)
        {
            // Count the number of elements less than or equal to el in the current row.
            count += min(el / i, n);
        }
        // Return the total count of elements less than or equal to el in the matrix.
        return count;
    }
};

int main()
{
    // Create an instance of the Solution class.
    Solution solution;
    // Define the dimensions of the matrix.
    int m = 3, n = 3;
    // Define the value of k.
    int k = 5;
    // Find the kth smallest number in the matrix.
    int kth_smallest = solution.findKthNumber(m, n, k);
    // Print the result.
    cout << "The " << k << "th smallest number in the matrix is: " << kth_smallest << endl;
    return 0;
}
