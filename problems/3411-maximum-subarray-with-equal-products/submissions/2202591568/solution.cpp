class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            int g = 0, l = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                if (prod > 100000) break;   
                g = gcd(g, nums[j]);
                l = l / gcd(l, nums[j]) * nums[j];
                if (prod == (long long)l * g) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};