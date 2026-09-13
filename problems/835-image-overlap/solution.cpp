class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int best = 0;

        for (int dx = -n + 1; dx <= n - 1; dx++) {
            for (int dy = -n + 1; dy <= n - 1; dy++) {
                int count = 0;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int ni = i + dx;
                        int nj = j + dy;

                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            if (img1[i][j] == 1 && img2[ni][nj] == 1) {
                                count++;
                            }
                        }
                    }
                }

                if (count > best) best = count;
            }
        }

        return best;
    }
};