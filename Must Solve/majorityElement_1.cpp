#include <vector>
#include <iostream>
using namespace std;
//Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& v) {
        int count = 0;
        int el = 0; // Initialize element that might be the majority

        // First pass: Find a candidate for majority element
        for(int i = 0; i < v.size(); i++) {
            if(count == 0) {
                el = v[i]; // Take the current element as a potential majority element
                count = 1; // Reset count for the new element
            } else if(v[i] == el) {
                // If the current element is the same as the potential majority, increase count
                count++;
            } else {
                // If different, decrease count
                count--;
            }
        }

        // Second pass: Verify if the candidate is indeed the majority element
        count = 0; // Reset count for verification
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == el) count++; // Count occurrences of the candidate element
        }

        // Check if the candidate is a majority element
        if(count > v.size() / 2) {
            return el; // Return the majority element
        }

        return -1; // If no majority element found, return -1
    }
};

int main() {
    Solution solution;
    // Example test case
    vector<int> v = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    cout << "The majority element is: " << solution.majorityElement(v) << endl;
    return 0;
}
