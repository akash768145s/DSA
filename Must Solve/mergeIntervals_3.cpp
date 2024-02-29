#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n = a.size(); // Get the number of intervals
        sort(a.begin(), a.end()); // Sort the intervals based on their start times
        
        vector<vector<int>> ans; // This will store the merged intervals
        for(int i = 0; i < n; i++) {
            // If 'ans' is empty or the current interval does not overlap with the last one in 'ans'
            if(ans.empty() || a[i][0] > ans.back()[1])
            //ans[ans.size() - 1][1] {
                ans.push_back(a[i]); // Add the current interval to 'ans'
            } else {
                // If there is an overlap, merge the current interval with the last one in 'ans'
                ans.back()[1] = max(ans.back()[1], a[i][1]);
            }
        }
        return ans; // Return the merged intervals
    }
};

// Driver code
int main() {
    // Example intervals
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    
    Solution sol; // Creating an object of Solution class
    vector<vector<int>> mergedIntervals = sol.merge(intervals); // Calling the merge function
    
    // Printing the merged intervals
    cout << "Merged intervals: " << endl;
    for(auto interval : mergedIntervals) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    
    return 0;
}
