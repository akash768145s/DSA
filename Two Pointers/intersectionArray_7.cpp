#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m);

int main()
{
    // Example arrays
    vector<int> A = {1, 2, 3, 4, 5};
    int n = A.size();
    vector<int> B = {2, 4, 6, 8};
    int m = B.size();

    // Find the intersection
    vector<int> intersection = findArrayIntersection(A, n, B, m);

    // Print the intersection
    cout << "Intersection: ";
    for (int num : intersection)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
// Function to find the intersection of two arrays
vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m)
{
    int i = 0, j = 0; // Initialize pointers for both arrays
    vector<int> ans;  // Vector to store the intersection elements

    // Loop until either array is fully traversed
    while (i < n && j < m)
    {
        if (A[i] < B[j])
        {
            // If current element of A is less than B's, move A's pointer
            i++;
        }
        else if (B[j] < A[i])
        {
            // If current element of B is less than A's, move B's pointer
            j++;
        }
        else
        {
            // If both elements are equal, add to answer and move both pointers
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans; // Return the intersection array
}
