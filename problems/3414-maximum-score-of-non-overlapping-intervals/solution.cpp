class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> order(n);
        for (int i = 0; i < n; i++) order[i] = i;

        sort(order.begin(), order.end(), [&](int a, int b) {
            return intervals[a][1] < intervals[b][1];
        });

        vector<long long> R(n);
        for (int i = 0; i < n; i++) R[i] = intervals[order[i]][1];

        vector<int> p(n + 1, 0);
        for (int m = 1; m <= n; m++) {
            long long startL = intervals[order[m - 1]][0];
            int lo = 0, hi = m - 2, ans = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (R[mid] < startL) { ans = mid; lo = mid + 1; }
                else hi = mid - 1;
            }
            p[m] = ans + 1;
        }

        vector<vector<long long>> dpWeight(5, vector<long long>(n + 1, 0));
        vector<vector<vector<int>>> dpIdxs(5, vector<vector<int>>(n + 1));

        for (int k = 1; k <= 4; k++) {
            for (int m = 1; m <= n; m++) {
                long long skipWeight = dpWeight[k][m - 1];
                vector<int> skipIdxs = dpIdxs[k][m - 1];

                long long baseWeight = dpWeight[k - 1][p[m]];
                vector<int> takeIdxs = dpIdxs[k - 1][p[m]];
                long long takeWeight = baseWeight + intervals[order[m - 1]][2];

                int origIndex = order[m - 1];
                int insertPos = 0;
                while (insertPos < (int)takeIdxs.size() && takeIdxs[insertPos] < origIndex) insertPos++;
                takeIdxs.insert(takeIdxs.begin() + insertPos, origIndex);

                bool takeIsBetter;
                if (takeWeight != skipWeight) {
                    takeIsBetter = (takeWeight > skipWeight);
                } else {
                    takeIsBetter = (takeIdxs < skipIdxs);
                }

                if (takeIsBetter) {
                    dpWeight[k][m] = takeWeight;
                    dpIdxs[k][m] = takeIdxs;
                } else {
                    dpWeight[k][m] = skipWeight;
                    dpIdxs[k][m] = skipIdxs;
                }
            }
        }

        return dpIdxs[4][n];
    }
};