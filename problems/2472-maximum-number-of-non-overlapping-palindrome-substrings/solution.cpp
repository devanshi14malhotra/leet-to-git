class Solution {
public:
    int maxPalindromes(string s, int k) {
    int n = s.size();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            isPal[i][j] = (s[i] == s[j]) && (j - i < 2 || isPal[i + 1][j - 1]);
        }
    }

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int len = k; len <= k + 1; len++) {
            int start = i - len;
            if (start >= 0 && isPal[start][i - 1])
                dp[i] = max(dp[i], dp[start] + 1);
        }
    }
    return dp[n];
}
};