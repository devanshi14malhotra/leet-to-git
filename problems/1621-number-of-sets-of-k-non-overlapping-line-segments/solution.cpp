class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1000000007;
        int total = n + k - 1;
        int r = 2 * k;

        vector<vector<long long>> C(total + 1, vector<long long>(total + 1, 0));

        for (int i = 0; i <= total; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        return (int) C[total][r];
    }
};