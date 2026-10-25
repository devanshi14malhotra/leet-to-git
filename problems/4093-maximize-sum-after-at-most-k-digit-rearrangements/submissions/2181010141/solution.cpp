class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long tot = 0;
        vector<long long> gains;
        for (int i=0; i<nums.size(); i++){
            tot += nums[i];
            string s = to_string(nums[i]);
            sort(s.begin(), s.end());
            reverse(s.begin(), s.end());
            long long best = stoll(s);
            gains.push_back(best-nums[i]);
        }
        sort(gains.begin(), gains.end());
        for (int i=0; i<k; i++){
            tot += gains[gains.size()-1-i];
        }
        return tot;
    }
};