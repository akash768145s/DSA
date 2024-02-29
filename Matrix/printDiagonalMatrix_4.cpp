#include <iostream>
#include <vector>
using namespace std;

// Function definition as provided
vector<int> matrixDiagonally(vector<vector<int>>& mat) {
    int m = mat.size(); // Get the number of rows
    int n = mat[0].size(); // Get the number of columns
    vector<int> result; // This will store the final sequence of values.

    // Traverse the first column of the matrix starting from the first row.
    for (int k = 0; k < m; k++) {
        int i = k;
        int j = 0;
        while (i >= 0 && j < n) {
            result.push_back(mat[i][j]); // Add the current element to the result.
            i = i - 1; // Move up in row.
            j = j + 1; // Move right in column.
        }
    }

    // Traverse the last row of the matrix starting from the second column.
    for (int k = 1; k < n; k++) {
        int i = m - 1;
        int j = k;
        while (i >= 0 && j < n) {
            result.push_back(mat[i][j]); // Add the current element to the result.
            i = i - 1; // Move up in row.
            j = j + 1; // Move right in column.
        }
    }

    return result; // Return the collected elements.
}

int main() {
    // Example matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Call the function with the example matrix
    vector<int> result = matrixDiagonally(mat);

    // Print the result
    cout << "Diagonally traversed matrix elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// Function to traverse the matrix diagonally in a zigzag manner
vector<int> matrixDiagonally(vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) return {};
    int m = mat[0].size();
    vector<int> result;
    
    int row = 0, col = 0;
    bool upward = true;
    
    for (int i = 0; i < n * m;) {
        if (upward) {
            for (; row >= 0 && col < m; row--, col++) {
                result.push_back(mat[row][col]);
                i++;
            }
            if (col == m) { // When it goes beyond the last column
                row += 2;
                col--;
            } else {
                row++;
            }
        } else {
            for (; col >= 0 && row < n; col--, row++) {
                result.push_back(mat[row][col]);
                i++;
            }
            if (row == n) { // When it goes beyond the last row
                row--;
                col += 2;
            } else {
                col++;
            }
        }
        upward = !upward; // Flip the direction
    }
    return result;
}

int main() {
    // Example matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Call the function with the example matrix
    vector<int> result = matrixDiagonally(mat);

    // Print the result
    cout << "Matrix traversed diagonally: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
