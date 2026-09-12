class Solution {
public:
    int minDays(int n) {

        vector<int> dp(n + 1, 1e9);

        // 0 points needs 0 days.
        // -1 handles the fact that the first streak
        // does not need a skip before it.
        dp[0] = -1;

        for (int score = 1; score <= n; score++) {

            // Try every possible streak length.
            for (long long k = 1;
                 k * (k + 1) / 2 <= score;
                 k++) {

                // Points earned by a streak of length k:
                // 1 + 2 + ... + k
                int points = k * (k + 1) / 2;

                // k days for earning the streak
                // + 1 day for the skip/reset
                //
                // dp[score - points] gives the minimum
                // days needed for the remaining score.
                dp[score] = min(
                    dp[score],
                    dp[score - points] + (int)k + 1
                );
            }
        }

        return dp[n];
    }
};
