#include <iostream> // For cout and endl
#include <vector>   // For using the vector class

using namespace std;

class Solution {
public:
    // Function to search a given target in a 2D matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // Number of rows
        int m = matrix[0].size(); // Number of columns

        int low = 0, high = n * m - 1; // Low and high pointers for binary search

        while (low <= high) {
            int mid = (low + high) / 2; // Calculating mid index
            int row = mid / m; // Converting mid to row index
            int col = mid % m; // Converting mid to column index

            if (matrix[row][col] == target) {
                return true; // Target found
            } else if (matrix[row][col] < target) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
        return false; // Target not found
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3; // Target value to search for

    bool found = solution.searchMatrix(matrix, target);
    if (found) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}
