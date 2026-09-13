class Solution {
public:
    bool isPal(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    string buildPal(string half, int L) {
        string res = half;
        int start;
        if (L % 2 == 0) start = (int)half.size() - 1;
        else start = (int)half.size() - 2;
        for (int i = start; i >= 0; i--) res += half[i];
        return res;
    }

    long long pw10(int k) {
        long long r = 1;
        for (int i = 0; i < k; i++) r *= 10;
        return r;
    }

    void consider(long long half, int halfLen, int L, long long num, int reqParity, long long &best) {
        long long lowB = pw10(halfLen - 1);
        long long highB = pw10(halfLen) - 1;
        if (half < lowB || half > highB) return;

        string hs = to_string(half);
        string pal = buildPal(hs, L);
        long long val = stoll(pal);
        if (val % 2 != reqParity) return;

        if (best == -1) best = val;
        else if (llabs(val - num) < llabs(best - num)) best = val;
    }

    long long minOperations(vector<int>& nums) {
        long long ans = 0;

        for (int idx = 0; idx < (int)nums.size(); idx++) {
            long long num = nums[idx];
            string s = to_string(num);
            if (isPal(s)) continue;

            int n = s.size();
            int reqParity = num % 2;
            long long best = -1;

            // length L = n
            int halfLen = (n + 1) / 2;
            long long H = stoll(s.substr(0, halfLen));
            int leadDigit = s[0] - '0';

            for (long long off = -2; off <= 2; off++) {
                consider(H + off, halfLen, n, num, reqParity, best);
            }
            if (leadDigit + 1 <= 9) {
                long long upHalf = (long long)(leadDigit + 1) * pw10(halfLen - 1);
                consider(upHalf, halfLen, n, num, reqParity, best);
            }
            if (leadDigit - 1 >= 1) {
                long long downHalf = (long long)(leadDigit - 1) * pw10(halfLen - 1) + (pw10(halfLen - 1) - 1);
                consider(downHalf, halfLen, n, num, reqParity, best);
            }

            // length L = n - 1 (shorter, only if n > 1)
            if (n > 1) {
                int L2 = n - 1;
                int halfLen2 = (L2 + 1) / 2;
                int leadDigit2 = (reqParity == 1) ? 9 : 8;
                long long half2 = (long long)leadDigit2 * pw10(halfLen2 - 1) + (pw10(halfLen2 - 1) - 1);
                consider(half2, halfLen2, L2, num, reqParity, best);
            }

            // length L = n + 1 (longer)
            int L3 = n + 1;
            int halfLen3 = (L3 + 1) / 2;
            int leadDigit3 = (reqParity == 1) ? 1 : 2;
            long long half3 = (long long)leadDigit3 * pw10(halfLen3 - 1);
            consider(half3, halfLen3, L3, num, reqParity, best);

            ans += llabs(best - num) / 2;
        }

        return ans;
    }
};