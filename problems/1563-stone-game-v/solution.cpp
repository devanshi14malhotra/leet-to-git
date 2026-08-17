class Solution {
public:
    vector<int> prefix;
    int dp[501][501];
    vector<vector<bool>> done;

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        done.assign(n, vector<bool>(n, false));
        return solve(0, n - 1);
    }
    int solve(int i, int j) {
        if (i == j) {
            return 0;
        }
        if (done[i][j]) {
            return dp[i][j];
        }
        done[i][j] = true;
        int best = 0;
        for (int k = i; k < j; k++) {
            int leftSum = prefix[k + 1] - prefix[i];
            int rightSum = prefix[j + 1] - prefix[k + 1];
            if (leftSum <= rightSum) {
                best = max(best, leftSum + solve(i, k));
            }
            if (rightSum <= leftSum) {
                best = max(best, rightSum + solve(k + 1, j));
            }
        }
        dp[i][j] = best;
        return best;
    }
};