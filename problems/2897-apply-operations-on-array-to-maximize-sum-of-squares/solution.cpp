class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1000000007;
        int cnt[30];
        for (int b = 0; b < 30; b++) cnt[b] = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int b = 0; b < 30; b++) {
                if ((nums[i] >> b) & 1) cnt[b]++;
            }
        }

        long long ans = 0;

        for (int t = 0; t < k; t++) {
            long long num = 0;
            for (int b = 0; b < 30; b++) {
                if (cnt[b] > 0) {
                    num += (1LL << b);
                    cnt[b]--;
                }
            }
            ans = (ans + (num % MOD) * (num % MOD)) % MOD;
        }

        return (int)ans;
    }
};