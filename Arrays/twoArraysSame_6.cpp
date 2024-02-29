#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;

class Solution {
public:
    // Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        unordered_map <int,int> hmap;
        for(int i = 0; i < N; i++) {
            hmap[A[i]]++; // Sets the corresponding frequency
        }
        for(int i = 0; i < N; i++) {
            hmap[B[i]]--; // All elements in the hashmap should cancel each other
        }
        for(auto i : hmap) { // Using auto datatype traversing through the Hashmap
            if(i.second != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<ll> A = {1, 2, 5, 4, 0};
    vector<ll> B = {2, 4, 5, 0, 1};
    int N = A.size();

    // Check if A and B are equal (considering rearrangement)
    bool isEqual = sol.check(A, B, N);

    // Output the result
    cout << (isEqual ? "1" : "0") << endl; // Expected Output: 1 (true)

    return 0;
}
