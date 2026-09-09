class Solution {
public:
    int minMoves(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        auto minIterator = min_element(nums.begin(), nums.end());
        int minValue = *minIterator;
        int n = nums.size();
        return total - n * minValue;
    }
};