class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 || dp[i][j] == 0) continue;

                for (int d = 0; d < 2; d++) {         
                    int r = i + (d == 1), c = j + (d == 0), dir = d;
                    while (r < n && c < m && grid[r][c] == 1) {
                        if (dir == 0) { dir = 1; r++; } 
                        else          { dir = 0; c++; } 
                    }
                    if (r < n && c < m)
                        dp[r][c] = (dp[r][c] + dp[i][j]) % MOD;
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};