#include <bits/stdc++.h>
using namespace std;

// Function to modify the matrix according to the rule: if an element is 0, set its entire row and column to 0.
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    int col0 = 1; // Flag to mark the first column.

    // First pass: mark rows and columns to be zeroed.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark the first element of the row.
                if (j != 0) matrix[0][j] = 0; // Mark the first element of the column, except for the first column.
                else col0 = 0; // If it's the first column, use col0 flag.
            }
        }
    }

    // Second pass: use marks to set elements to zero.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) { // If the row or column is marked,
                matrix[i][j] = 0; // set the element to zero.
            }
        }
    }

    // Zeroing the first row if needed.
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) matrix[0][j] = 0;
    }

    // Zeroing the first column if needed, based on col0 flag.
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 0, 6}, {7, 8, 9}};
    int n = 3, m = 3; // Dimensions of the matrix

    // Call the function
    vector<vector<int>> result = zeroMatrix(matrix, n, m);

    // Print the modified matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
