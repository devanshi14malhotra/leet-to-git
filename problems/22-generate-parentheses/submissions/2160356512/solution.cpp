class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};

        for (int count = 1; count <= n; count++) {
            for (int i = 0; i < count; i++) {
                for (string a : dp[i]) {
                    for (string b : dp[count - 1 - i]) {
                        dp[count].push_back("(" + a + ")" + b);
                    }
                }
            }
        }

        return dp[n];
    }
};