#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        // Create a dynamic programming array to store the ugly numbers
        vector<int> dp(n);
        // Initialize the first ugly number as 1
        dp[0] = 1;

        // Pointers for multiples of 2, 3, and 5
        int p2 = 0, p3 = 0, p5 = 0;

        // Loop to fill the dp array with the next ugly numbers
        for (int i = 1; i < n; i++)
        {
            // Calculate the next ugly number as the minimum of multiples of 2, 3, and 5
            int nextUgly = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            // Store the next ugly number in the dp array
            dp[i] = nextUgly;

            // Update pointers based on the multiples found
            if (nextUgly == dp[p2] * 2)
                p2++;
            if (nextUgly == dp[p3] * 3)
                p3++;
            if (nextUgly == dp[p5] * 5)
                p5++;
        }

        // Return the nth ugly number
        return dp[n - 1];
    }
};

// Driver code
int main()
{
    // Create an instance of the Solution class
    Solution solution;
    // Define the value of n (e.g., find the 10th ugly number)
    int n = 10;
    // Find the nth ugly number
    int ugly = solution.nthUglyNumber(n);
    // Output the result
    cout << "The " << n << "th ugly number is: " << ugly << endl;
    return 0;
}
