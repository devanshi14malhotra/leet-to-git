class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> cnt;
            vector<int> order;

            for (int j = i; j < n; j++) {
                if (cnt[nums[j]] == 0) order.push_back(nums[j]);
                cnt[nums[j]]++;

                bool ok = true;
                for (int t = 0; t < order.size(); t++) {
                    if (cnt[order[t]] != t + 1) {
                        ok = false;
                        break;
                    }
                }

                if (ok) ans++;
            }
        }

        return ans;
    }
};