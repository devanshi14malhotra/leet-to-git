class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int best = 1;

        for (int i = 0; i < n; i++) {
            long long r = nums[i] % k;

            for (int j = i; j < n; j++) {
                if (nums[j] % k != r) break; 

                long long len = j - i + 1;
                if (((len - 1) * r) % k == 0) {
                    best = max(best, (int)len);
                }
            }
        }

        return best;
    }
};