#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(); // Get the number of rows in the matrix.
    int m = matrix[0].size(); // Get the number of columns in the matrix.
    int low = 0, high = n * m - 1; // Set initial search boundaries.
    
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate mid point.
        int row = mid / m; // Calculate row number of the mid point.
        int col = mid % m; // Calculate column number of the mid point.
        
        if (matrix[row][col] == target) return true; // Target found.
        else if (matrix[row][col] < target) low = mid + 1; // Search in the right half.
        else high = mid - 1; // Search in the left half.
    }
    
    return false; // Target not found.
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3; // Target value to search for
    
    // Call the searchMatrix function
    bool found = searchMatrix(matrix, target);
    
    // Output result
    if (found) {
        cout << "The target " << target << " is found in the matrix." << endl;
    } else {
        cout << "The target " << target << " is not found in the matrix." << endl;
    }
    
    return 0;
}
