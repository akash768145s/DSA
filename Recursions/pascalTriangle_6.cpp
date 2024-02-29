#include <iostream>
#include <vector>
using namespace std;

// Function to generate a single row of Pascal's Triangle
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); // The first element of each row is always 1
    for (int col = 1; col < row; col++) {
        // Calculate the next element in the row based on the formula
        ans = ans * (row - col) / col;
        ansRow.push_back(static_cast<int>(ans));
    }
    return ansRow;
}

// Function to generate Pascal's Triangle up to N rows
vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++) {
        // Generate each row and add it to the ans vector
        vector<int> ansRow = generateRow(i);
        ans.push_back(ansRow);
    }
    return ans;
}

// Driver code
int main() {
    int N;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> N; // Input the number of rows

    vector<vector<int>> triangle = pascalTriangle(N); // Generate the triangle

    // Print Pascal's Triangle
    for (const auto &row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl; // New line after each row
    }

    return 0;
}
