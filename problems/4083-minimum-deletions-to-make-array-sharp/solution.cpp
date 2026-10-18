class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int del=0;
        for (int i=1; i<nums.size(); i++){
            if (nums[i]==nums[i-1]) del++;
        }
        return del;
    }
};