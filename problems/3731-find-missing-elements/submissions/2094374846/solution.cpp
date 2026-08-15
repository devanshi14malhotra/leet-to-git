class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0], mx = nums[0];
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < mn) mn = nums[i];
            if (nums[i] > mx) mx = nums[i];
        }
        
        vector<bool> present(mx + 1, false);
        for (int i = 0; i < n; i++) {
            present[nums[i]] = true;
        }
        
        vector<int> result;
        for (int val = mn; val <= mx; val++) {
            if (!present[val]) {
                result.push_back(val);
            }
        }
        
        return result;
    }
};