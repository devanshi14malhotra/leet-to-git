class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            int seen[101];
            for (int v = 0; v <= 100; v++) seen[v] = 0;

            int distinct = 0;

            for (int j = i; j < n; j++) {
                if (seen[nums[j]] == 0) {
                    seen[nums[j]] = 1;
                    distinct++;
                }
                total += distinct * distinct;
            }
        }

        return total;
    }
};