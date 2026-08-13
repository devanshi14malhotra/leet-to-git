class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int best = 0;

        for (int right = 0; right < nums.size(); right++) {
            int val = nums[right];
            freq[val] = freq[val] + 1;

            while (freq[val] > k) {
                int leftVal = nums[left];
                freq[leftVal] = freq[leftVal] - 1;
                left = left + 1;
            }

            int windowSize = right - left + 1;
            if (windowSize > best) {
                best = windowSize;
            }
        }

        return best;
    }
};