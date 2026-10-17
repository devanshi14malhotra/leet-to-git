class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> a;
        for (int i = 0; i < n; i++) {
            int s = 0, x = nums[i];
            while (x > 0) { s += x % 10; x /= 10; }
            a.push_back({s, nums[i], i});
        }
        sort(a.begin(), a.end());

        vector<bool> vis(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            int len = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = a[j][2];
                len++;
            }
            swaps += len - 1;
        }
        return swaps;
    }
};