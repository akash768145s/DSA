#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> matrix) {
        int cnt_min = INT_MAX; // Initialize the minimum count of 1's to the maximum possible value.
        int index = -1; // Initialize the index of the row with the minimum 1's to -1.

        // Traverse the matrix row by row.
        for (int i = 0; i < n; i++) {
            int cnt_ones = 0; // Count of 1's in the current row.
            // Count the number of 1's in the current row.
            for (int j = 0; j < m; j++) {
                cnt_ones += matrix[i][j];
            }
            // If the current row has fewer 1's than the previous minimum, update the minimum and the index.
            if (cnt_ones < cnt_min) {
                cnt_min = cnt_ones;
                index = i;
            }
        }
        // Return the 1-based index of the row with the minimum number of 1's.
        return index + 1;
    }
};

int main() {
    // Example matrix.
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 0}
    };
    int n = 3; // Number of rows.
    int m = 3; // Number of columns.

    Solution sol;
    // Call the minRow function and store the result.
    int rowWithMinOnes = sol.minRow(n, m, matrix);

    // Output the result.
    cout << "The row with the minimum number of 1's is: " << rowWithMinOnes << endl;

    return 0;
}
