class Solution {
public:
    long long countCommas(long long n) {
        long long tot = 0;
        long long l = 1;
        long long h = 9;
        long long d = 1;
        while (l <= n) {
            long long rangeHi = min(h, n);
            long long count = rangeHi - l + 1; 
            long long commasPerNumber = (d - 1) / 3;
            tot += count * commasPerNumber;
            d++;
            l = h + 1;
            h = h * 10 + 9; 
        }

        return tot;
    }
};