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
