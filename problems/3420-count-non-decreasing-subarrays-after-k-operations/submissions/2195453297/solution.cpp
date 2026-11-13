class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), r = n - 1;
        deque<pair<long long, long long>> dq; 
        long long ans = 0, mx = 0, sum = 0;
        for (int l = n - 1; l >= 0; l--) {
            sum += nums[l];
            long long c = 1;
            while (!dq.empty() && dq.front().first <= nums[l]) {
                c += dq.front().second;
                mx -= dq.front().first * dq.front().second;
                dq.pop_front();
            }
            dq.push_front({nums[l], c});
            mx += nums[l] * c;
            while (mx - sum > k) {
                mx -= dq.back().first;
                if (--dq.back().second == 0) dq.pop_back();
                sum -= nums[r--];
            }
            ans += r - l + 1;
        }
        return ans;
    }
};