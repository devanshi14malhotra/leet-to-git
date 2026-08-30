class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
    
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        
        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[idx[j + 1]] - nums[idx[j]] <= limit) {
                j++;
            }
            vector<int> groupIndices(idx.begin() + i, idx.begin() + j + 1);
            vector<int> groupValues;
            for (int k = i; k <= j; k++) groupValues.push_back(nums[idx[k]]);
            
            sort(groupIndices.begin(), groupIndices.end()); 
            
            for (int k = 0; k < (int)groupIndices.size(); k++) {
                result[groupIndices[k]] = groupValues[k];
            }
            
            i = j + 1;
        }
        
        return result;
    }
};