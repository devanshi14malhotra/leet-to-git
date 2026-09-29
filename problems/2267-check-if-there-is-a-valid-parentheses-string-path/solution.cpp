class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;
        if ((m + n - 1) % 2 != 0) return false; 

        int maxBal = m + n; 
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(maxBal + 1, false)));

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int delta = (grid[i][j] == '(') ? 1 : -1;

                for (int bal = 0; bal <= maxBal; bal++) {
                    bool canReach = false;

                    if (i > 0 && bal - delta >= 0 && bal - delta <= maxBal) {
                        if (dp[i-1][j][bal - delta]) canReach = true;
                    }
                    if (j > 0 && bal - delta >= 0 && bal - delta <= maxBal) {
                        if (dp[i][j-1][bal - delta]) canReach = true;
                    }

                    if (bal >= 0) dp[i][j][bal] = canReach;
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};