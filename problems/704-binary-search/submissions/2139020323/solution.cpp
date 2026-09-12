class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return (l > 0 && nums[l - 1] == target) ? l - 1 : -1;
    }
};