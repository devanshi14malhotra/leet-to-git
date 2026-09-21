class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k, 0);      // dp[r] = count of subarrays ending at current index with product % k == r
        vector<long long> result(k, 0);  // final answer

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i] % k;
            vector<long long> newDp(k, 0);
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newR = (r * val) % k;
                    newDp[newR] += dp[r];
                }
            }
            newDp[val] += 1;

            dp = newDp;

            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }

        return result;
    }
};