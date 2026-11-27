class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), minPrice = INT_MAX;
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int value = 1;
            for (int j = 0; j < n; j++)
                if (i != j && items[j][0] % items[i][0] == 0) value++;
            minPrice = min(minPrice, items[i][1]);

            for (int b = budget; b >= items[i][1]; b--)
                dp[b] = max(dp[b], dp[b - items[i][1]] + value);
        }

        for (int b = minPrice; b <= budget; b++)
            dp[b] = max(dp[b], dp[b - minPrice] + 1);

        return dp[budget];
    }
};