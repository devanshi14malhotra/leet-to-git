class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n+1,0);
        vector<int> dp(n+1,0);
        vector<long long> lastSum(n+1,0);
        deque<int> dq;
        dq.push_back(0);
        for (int i=1; i<=n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
            while (dq.size() >= 2 && prefix[dq[1]] + lastSum[dq[1]] <= prefix[i]) dq.pop_front();

            int j = dq.front();
            dp[i] = dp[j] + 1;
            lastSum[i] = prefix[i] - prefix[j];
            while (!dq.empty() && prefix[dq.back()] + lastSum[dq.back()] >= prefix[i] + lastSum[i]) dq.pop_back();

            dq.push_back(i);
        }
        return dp[n];
    }
};