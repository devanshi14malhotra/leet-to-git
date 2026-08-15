class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        for (int i = 0; i < n; i++) {
            totalXor = totalXor ^ nums[i];
        }
        if (totalXor != 0) {
            return n;
        }
        bool hasNonZero = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                hasNonZero = true;
                break;
            }
        }
        if (!hasNonZero) {
            return 0;
        }
        return n - 1;
    }
};