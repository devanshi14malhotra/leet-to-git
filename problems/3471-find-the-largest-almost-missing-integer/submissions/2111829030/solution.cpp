class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        unordered_map<int, int> subarray_count;
        int n = nums.size();
        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> unique_elements;
            for (int j = i; j < i + k; ++j) {
                unique_elements.insert(nums[j]);
            }
            for (int val : unique_elements) {
                subarray_count[val]++;
            }
        }
        int ans = -1;
        for (const auto& [val, count] : subarray_count) {
            if (count == 1) {
                ans = max(ans, val);
            }
        }
        return ans;
    }
};