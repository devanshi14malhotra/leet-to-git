class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> lmax(n), rmin(n);

        lmax[0] = nums[0];
        for (int i = 1; i < n; i++)
            lmax[i] = max(lmax[i - 1], nums[i]);

        rmin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rmin[i] = min(rmin[i + 1], nums[i]);

        for (int i = 0; i < n; i++) {
            if (lmax[i] - rmin[i] <= k) return i;
        }

        return -1;
    }
};