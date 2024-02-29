#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st; // Using set to store unique triplets
        for(int i = 0; i < n; i++) {
            set<int> hashset; // Using hashset to store the numbers we've seen
            for(int j = i + 1; j < n; j++) {
                int third = -(nums[i] + nums[j]); // The value needed to complete the triplet
                // If 'third' is found in 'hashset', it means we have a valid triplet
                if(hashset.find(third) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end()); // Sort the triplet to ensure uniqueness
                    st.insert(temp); // Insert the sorted triplet into the set
                }
                hashset.insert(nums[j]); // Add the current number to 'hashset'
            }
        }
        vector<vector<int>> ans(st.begin(), st.end()); // Convert the set to vector
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; // Input array
    vector<vector<int>> result = solution.threeSum(nums);

    // Print the triplets
    for(const auto &triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        // Skip the duplicate elements for 'i'
        if(i > 0 && nums[i] == nums[i-1]) continue;
        
        int j = i + 1;
        int k = n - 1;
        
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            
            if(sum < 0) {
                j++;
            } else if(sum > 0) {
                k--;
            } else {
                // Found a triplet
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                
                // Skip the duplicate elements for 'j' and 'k'
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    
    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; // Example input
    vector<vector<int>> result = threeSum(nums);
    
    cout << "Unique triplets are:" << endl;
    for(const auto& triplet : result) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]" << endl;
    }
    
    return 0;
}
