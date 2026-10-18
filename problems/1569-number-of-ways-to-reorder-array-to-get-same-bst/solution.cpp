class Solution {
public:
    long long MOD = 1000000007;
    vector<vector<long long>> C;

    long long ways(vector<int> arr) {
        if (arr.size() <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[0]) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }

        long long mix = C[left.size() + right.size()][left.size()];
        return mix * ways(left) % MOD * ways(right) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        C = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        return (int)((ways(nums) - 1 + MOD) % MOD);
    }
};