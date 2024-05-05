#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    // Function to check if it's possible to make m bouquets each with k flowers within day days
    bool possible(vector<int>& arr, int day, int m, int k) {
        int n = arr.size(); // size of the array
        int cnt = 0;
        int noOfB = 0;
        // count the number of bouquets:
        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                cnt++; // increment count of flowers in a bouquet
            } else {
                noOfB += (cnt / k); // increment bouquet count
                cnt = 0; // reset flower count for the next bouquet
            }
        }
        noOfB += (cnt / k); // add remaining flowers to the bouquet count
        return noOfB >= m; // check if the required number of bouquets can be made
    }

    // Function to find the minimum number of days required to make m bouquets each with k flowers
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k; // compute the required number of flowers
        int n = bloomDay.size(); // size of the array
        if (val > n) return -1; // impossible case: not enough flowers
        // find maximum and minimum bloom day:
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]); // find minimum bloom day
            maxi = max(maxi, bloomDay[i]); // find maximum bloom day
        }

        // apply binary search to find the minimum number of days required
        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2; // calculate mid day
            if (possible(bloomDay, mid, m, k)) { // check if it's possible to make bouquets within mid days
                high = mid - 1; // update high
            } else {
                low = mid + 1; // update low
            }
        }
        return low; // return the minimum number of days required
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> bloomDay = {1, 2, 1, 2, 7, 2, 2, 3, 1};
    int m = 3;
    int k = 2;
    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum number of days required: " << result << endl; 
    return 0;
}