#include <bits/stdc++.h>
using namespace std;

// lowerBound function finds the first occurrence of x in arr[].
int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n; // Start with the worst-case answer (not found).

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // If arr[mid] is greater than or equal to x, it could be the answer.
        if (arr[mid] >= x)
        {
            ans = mid; // Update answer to current index.
            high = mid - 1; // Look for a smaller index on the left.
        }
        else
        {
            low = mid + 1; // x is greater, look on the right side.
        }
    }
    return ans; // Return the index of the first occurrence of x or n if not found.
}

// rowWithMax1s function finds the row with the maximum number of 1's.
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cnt_max = 0; // Store the maximum count of 1's found so far.
    int index = -1; // Store the index of the row with the maximum count of 1's.

    // Traverse the rows.
    for (int i = 0; i < n; i++)
    {
        // Calculate the number of 1's in the current row using lowerBound.
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        // If the current row has more 1's than the maximum found so far, update cnt_max and index.
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index; // Return the index of the row with the maximum number of 1's.
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    // Call rowWithMax1s with the matrix, number of rows (n), and columns (m) to find the row with maximum 1's.
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';
}
