class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = nums[0];

        bool asc = true, desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) asc = false;
            if (nums[i] != ((k - i) % n + n) % n) desc = false;
        }

        int best = INT_MAX;

        if (asc) {
            if (k == 0) best = 0;
            else best = min(n - k, k + 2);
        }

        if (desc) {
            int k2 = (k + 1) % n;
            if (k2 == 0) best = min(best, 1);
            else best = min(best, 1 + min(k2, n - k2));
        }

        return best == INT_MAX ? -1 : best;
    }
};