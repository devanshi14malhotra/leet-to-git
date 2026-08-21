class Solution {
public:
    vector<int> coins;
    int n;

    long long findMinCoin() {
        long long minVal = coins[0];
        for (int i = 1; i < n; i++) {
            if (coins[i] < minVal) {
                minVal = coins[i];
            }
        }
        return minVal;
    }

    long long computeGcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long countUpTo(long long amt) {
        long long total = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcmVal = 1;
            int numCoinsInSubset = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    long long g = computeGcd(lcmVal, coins[i]);
                    lcmVal = (lcmVal / g) * coins[i];
                    numCoinsInSubset++;
                }
            }

            if (lcmVal > amt) {
                continue;
            }

            long long multiplesOfLcm = amt / lcmVal;

            if (numCoinsInSubset % 2 == 1) {
                total = total + multiplesOfLcm;
            } else {
                total = total - multiplesOfLcm;
            }
        }

        return total;
    }

    long long findKthSmallest(vector<int>& coinsInput, int k) {
        coins = coinsInput;
        n = coins.size();

        long long lo = 1;
        long long hi = (long long)k * findMinCoin();

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (countUpTo(mid) < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};