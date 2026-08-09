class Solution {
public:
    vector<int> suffixSum;
    vector<vector<int>> memo;

    int stoneGameII(vector<int>& piles) {
        int numberOfPiles = piles.size();
        suffixSum.assign(numberOfPiles + 1, 0);
        for (int i = numberOfPiles - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        memo.assign(numberOfPiles, vector<int>(numberOfPiles + 1, -1));
        return solve(0, 1);
    }

    int solve(int index, int multiplier) {
        int numberOfPiles = suffixSum.size() - 1;
        if (2 * multiplier >= numberOfPiles - index) {
            return suffixSum[index];
        }
        if (memo[index][multiplier] != -1) {
            return memo[index][multiplier];
        }

        int best = 0;
        for (int stonesTaken = 1; stonesTaken <= 2 * multiplier; stonesTaken++) {
            best = max(best, suffixSum[index] - solve(index + stonesTaken, max(multiplier, stonesTaken)));
        }

        return memo[index][multiplier] = best;
    }
};