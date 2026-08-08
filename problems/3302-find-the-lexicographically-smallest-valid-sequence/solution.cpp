class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> positions(26);
        for (int i = 0; i < n; i++) positions[word1[i] - 'a'].push_back(i);

        auto largestBelow = [&](int c, int bound) -> int {
            vector<int>& v = positions[c];
            auto it = lower_bound(v.begin(), v.end(), bound);
            if (it == v.begin()) return -1;
            --it;
            return *it;
        };

        vector<int> exact(m + 1), one(m + 1);
        exact[m] = one[m] = n;
        for (int i = m - 1; i >= 0; i--) {
            exact[i] = (exact[i + 1] <= 0) ? -1 : largestBelow(word2[i] - 'a', exact[i + 1]);
            int optExact = (one[i + 1] <= 0) ? -1 : largestBelow(word2[i] - 'a', one[i + 1]);
            int optMismatch = exact[i + 1] - 1;
            one[i] = max(optExact, optMismatch);
        }
        if (one[0] == -1) return {};

        vector<int> result;
        int pointer = 0;
        bool mismatchUsed = false;

        for (int i = 0; i < m; i++) {
            bool placed = false;
            while (pointer < n && !placed) {
                if (word1[pointer] == word2[i] && !mismatchUsed && pointer + 1 <= one[i + 1]) {
                    result.push_back(pointer); pointer++; placed = true;
                } else if (word1[pointer] == word2[i] && mismatchUsed && pointer + 1 <= exact[i + 1]) {
                    result.push_back(pointer); pointer++; placed = true;
                } else if (!mismatchUsed && pointer + 1 <= exact[i + 1]) {
                    mismatchUsed = true;
                    result.push_back(pointer); pointer++; placed = true;
                } else {
                    pointer++;
                }
            }
            if (!placed) return {};
        }
        return result;
    }
};