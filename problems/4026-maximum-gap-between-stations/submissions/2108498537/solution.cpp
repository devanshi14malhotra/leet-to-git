class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();
        vector<int> leftIdx(n), rightIdx(n);
        int p = 0;
        for (int i = 0; i < n; i++) {
            while (station[p] != skill[i]) p++;
            leftIdx[i] = p;
            p++;
        }
        p = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (station[p] != skill[i]) p--;
            rightIdx[i] = p;
            p--;
        }
        if (n == 1) return 0;
        int maxGap = 0;
        for (int i = 1; i < n; i++) {
            maxGap = max(maxGap, rightIdx[i] - leftIdx[i - 1]);
        }
        return maxGap;
    }
};