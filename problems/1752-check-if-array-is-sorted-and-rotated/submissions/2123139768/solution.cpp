class Solution {
public:
    bool check(vector<int>& nums) {
        int N = nums.size();
        int count = 1;

        for (int i = 1; i < 2 * N; i++) {
            if (nums[(i - 1) % N] <= nums[i % N]) {
                count++;
            } else {
                count = 1;
            }
            if (count == N) {
                return true;
            }
        }

        return N == 1;
    }
};