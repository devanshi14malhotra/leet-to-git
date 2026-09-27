class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(501, 0);
        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < n; r++) {
            int x = nums[r];

            while (l < r) {
                bool bad = false;
                for (int a = 1; a <= 500 && !bad; a++) {
                    int b = x - a;
                    if (b < 1 || b > 500) continue;
                    if (a == b) {
                        if (freq[a] >= 2) bad = true;
                    } else {
                        if (freq[a] >= 1 && freq[b] >= 1) bad = true;
                    }
                }
                for (int y = 1; y <= 500 && !bad; y++) {
                    if (freq[y] == 0) continue;
                    int z = x + y;
                    if (z > 500) continue;
                    if (z == y) {
                        if (freq[y] >= 2) bad = true;
                    } else {
                        if (freq[z] >= 1) bad = true;
                    }
                }

                if (!bad) break;

                freq[nums[l]]--;
                l++;
            }

            freq[x]++;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};