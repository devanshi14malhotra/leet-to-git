class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int best = INT_MAX;
        for (int r = 0; r < n; r++) {
            int cost = r;
            for (int i = 0; i < n / 2; i++) {
                int a = s[(r + i) % n] - 'a';
                int b = s[(r + n - 1 - i) % n] - 'a';
                int d = abs(a - b);
                cost += min(d, 26 - d);
            }
            best = min(best, cost);
        }
        return best;
    }
};