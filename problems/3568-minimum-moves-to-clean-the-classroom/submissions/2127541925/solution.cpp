class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sr = 0, sc = 0;
        int litterCount = 0;
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        int full = (1 << litterCount) - 1;
        if (full == 0) return 0;

        int maskCount = full + 1;
        int energyCount = energy + 1;
        vector<bool> visited(m * n * maskCount * energyCount, false);

        queue<int> q;
        int startKey = ((sr * n + sc) * maskCount + 0) * energyCount + energy;
        visited[startKey] = true;
        q.push(startKey);

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int moves = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            moves++;
            for (int k = 0; k < levelSize; k++) {
                int key = q.front();
                q.pop();

                int e = key % energyCount;
                int rest = key / energyCount;
                int mask = rest % maskCount;
                int pos = rest / maskCount;
                int r = pos / n;
                int c = pos % n;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;
                    if (e - 1 < 0) continue;

                    int ne = (classroom[nr][nc] == 'R') ? energy : e - 1;

                    int nmask = mask;
                    if (id[nr][nc] != -1) {
                        nmask = nmask | (1 << id[nr][nc]);
                    }

                    if (nmask == full) return moves;

                    int nkey = ((nr * n + nc) * maskCount + nmask) * energyCount + ne;
                    if (visited[nkey]) continue;
                    visited[nkey] = true;
                    q.push(nkey);
                }
            }
        }

        return -1;
    }
};