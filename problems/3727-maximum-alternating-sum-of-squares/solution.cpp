class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq;

        for (int i = 0; i < n; i++) {
            sq.push_back((long long)nums[i] * nums[i]);
        }

        sort(sq.begin(), sq.end());

        int minusCount = n / 2;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (i < minusCount) ans -= sq[i];
            else ans += sq[i];
        }

        return ans;
    }
};