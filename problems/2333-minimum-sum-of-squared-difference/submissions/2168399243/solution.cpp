class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> count(100002, 0);
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            count[d]++;
            total += d;
        }

        if (k >= total) return 0;

        for (int d = 100000; d >= 1 && k > 0; d--) {
            long long moved = min(k, count[d]);
            count[d] -= moved;
            count[d - 1] += moved;
            k -= moved;
        }

        long long ans = 0;
        for (long long d = 1; d <= 100000; d++) ans += count[d] * d * d;
        return ans;
    }
};