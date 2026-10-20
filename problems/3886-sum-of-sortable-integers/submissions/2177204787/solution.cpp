class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            int prevMax = 0;

            for (int start = 0; start < n && ok; start += k) {
                int drops = 0;
                int mn = nums[start], mx = nums[start];

                for (int i = start; i < start + k; i++) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);

                    int next = (i + 1 < start + k) ? nums[i + 1] : nums[start];
                    if (nums[i] > next) drops++;
                }

                if (drops > 1) ok = false;
                if (mn < prevMax) ok = false;
                prevMax = mx;
            }

            if (ok) total += k;
        }

        return total;
    }
};