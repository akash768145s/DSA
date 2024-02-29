#include <vector>
using namespace std;
#include <iostream>
vector<vector<int>> rotateMatrix(int N, int M, int K, vector<vector<int>>& Mat) {
    vector<int> temp(M);
    K %= M;
    for (int i = 0; i < N; i++) {
        // Copy the first K elements to a temporary array
        for (int t = 0; t < K; t++) {
            temp[t] = Mat[i][t];
        }
        // Shift the remaining elements to the left by K positions
        for (int j = K; j < M; j++) {
            Mat[i][j - K] = Mat[i][j];
        }
        // Copy the elements from the temporary array to the last K positions
        for (int j = M - K; j < M; j++) {
            Mat[i][j] = temp[j - M + K];
        }
    }
    return Mat;
}
int main() {
    // Define matrix dimensions and the number of rotations
    int N = 3, M = 3, K = 2;
    
    // Initialize the matrix
    vector<vector<int>> Mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Rotate the matrix K times
    vector<vector<int>> rotatedMat = rotateMatrix(N, M, K, Mat);
    
    // Print the rotated matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << rotatedMat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}