class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = 0, miss = 0;
        for (int x : nums) {
            int i = abs(x) - 1;
            if (nums[i] < 0) dup = abs(x);
            else nums[i] = -nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0) miss = i + 1;
        return {dup, miss};
    }
};