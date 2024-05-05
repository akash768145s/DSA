#include <iostream>
#include <vector>
using namespace std;

// Finds the index of the maximum element in a given column of a 2D matrix.
int findMaxIndex(vector<vector<int>> &mat, int n, int m, int col)
{
    int maxValue = -1; // Initialize the maximum value as -1 (assuming all elements are non-negative).
    int index = -1;    // Initialize the index of the maximum element as -1.
    for (int i = 0; i < n; i++)
    { // Loop through all rows of the given column.
        if (mat[i][col] > maxValue)
        {                           // If the current element is greater than the current maximum...
            maxValue = mat[i][col]; // Update the maximum value to the current element.
            index = i;              // Update the index to the current row index.
        }
    }
    return index; // Return the index of the maximum element in the given column.
}

// Finds a peak element in a 2D matrix, where a peak is greater than or equal to its neighbors.
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();        // Number of rows in the matrix.
    int m = mat[0].size();     // Number of columns in the matrix.
    int low = 0, high = m - 1; // Set the initial search range for binary search on columns.
    while (low <= high)
    {                                                   // Continue the loop until the search range is valid.
        int mid = (low + high) / 2;                     // Calculate the mid column for the current search range.
        int maxRowIndex = findMaxIndex(mat, n, m, mid); // Find the index of the maximum element in the mid column.
        // Check the values of the elements to the left and right of the maximum element in the mid column.
        int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1; // If there is a left neighbor, get its value; otherwise, -1.
        int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : -1; // If there is a right neighbor, get its value; otherwise, -1.

        if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
        {                              // If the current element is a peak...
            return {maxRowIndex, mid}; // Return its coordinates (row index, column index).
        }
        else if (left > mat[maxRowIndex][mid])
        {                   // If the left neighbor is greater...
            high = mid - 1; // Move the search range to the left.
        }
        else
        { // Otherwise, move the search range to the right.
            low = mid + 1;
        }
    }
    return {-1, -1}; // Return {-1, -1} if no peak is found (unlikely in practice given typical problem constraints).
}

int main()
{
    // Example matrix
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}};

    // Call findPeakGrid and store the result
    vector<int> peak = findPeakGrid(mat);

    // Check if a peak was found and print the result
    if (peak[0] != -1 && peak[1] != -1)
    {
        cout << "Peak found at: (" << peak[0] << ", " << peak[1] << ") with value " << mat[peak[0]][peak[1]] << endl;
    }
    else
    {
        cout << "No peak found." << endl;
    }

    return 0;
}