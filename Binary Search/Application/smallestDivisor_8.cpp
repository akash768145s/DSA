#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    // Function to calculate the sum of array elements divided by a divisor
    int sumByD(vector<int> &arr, int div)
    {
        int sum = 0;
        int n = arr.size();
        // Iterate through the array
        for (int i = 0; i < n; i++)
        {
            // Add the ceil value of arr[i]/div to the sum
            sum = sum + ceil((double)(arr[i]) / (double)(div));
        }
        return sum;
    }

    // Function to find the smallest divisor such that the sum of array elements divided by it is less than or equal to a given limit
    int smallestDivisor(vector<int> &arr, int limit)
    {
        // Set the lower and upper bounds for binary search
        int low = 1, high = *max_element(arr.begin(), arr.end());
        while (low <= high)
        {
            // Calculate the mid value
            int mid = (low + high) / 2;
            // If the sum of array elements divided by mid is less than or equal to the limit, update the upper bound
            if (sumByD(arr, mid) <= limit)
            {
                high = mid - 1;
            }
            // If the sum exceeds the limit, update the lower bound
            else
            {
                low = mid + 1;
            }
        }
        // Return the smallest divisor
        return low;
    }
};

int main()
{
    // Example usage
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 10;
    cout << "Smallest divisor: " << sol.smallestDivisor(arr, limit) << endl;
    return 0;
}
