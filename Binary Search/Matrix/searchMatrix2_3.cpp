#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // The searchMatrix method searches for a target value within a 2D matrix.
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(); // Number of rows in the matrix.
        int m = mat[0].size(); // Number of columns in the matrix.
        int row = 0, col = m - 1; // Start from the top-right corner of the matrix.
        
        while (row < n && col >= 0) { // Ensure indices are within the matrix bounds.
            if (mat[row][col] == target) // If the target is found, return true.
                return true;
            else if (mat[row][col] < target) // If the current element is less than the target, move down.
                row++;
            else // If the current element is greater than the target, move left.
                col--;
        }
        return false; // If the loop exits, the target was not found.
    }
};

int main() {
    // Create an instance of the Solution class.
    Solution solution;
    
    // Example matrix (must be sorted row-wise and column-wise for the algorithm to work).
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    
    // Target value to search for.
    int target = 5;
    
    // Call the searchMatrix function and store the result.
    bool found = solution.searchMatrix(matrix, target);
    
    // Print the result.
    if (found) {
        cout << "The target " << target << " is found in the matrix." << endl;
    } else {
        cout << "The target " << target << " is not found in the matrix." << endl;
    }
    
    return 0;
}
