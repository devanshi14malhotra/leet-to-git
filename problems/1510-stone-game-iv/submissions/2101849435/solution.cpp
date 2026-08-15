class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                int rem = i - j * j;
                if (!dp[rem]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};