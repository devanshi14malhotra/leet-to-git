class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] <= 0) continue;

                long long sum = 0;
                vector<pair<int,int>> st;
                st.push_back({i, j});
                sum += grid[i][j];
                grid[i][j] = 0;

                while (!st.empty()) {
                    pair<int,int> cur = st.back();
                    st.pop_back();

                    for (int d = 0; d < 4; d++) {
                        int nr = cur.first + dr[d];
                        int nc = cur.second + dc[d];

                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                        if (grid[nr][nc] <= 0) continue;

                        sum += grid[nr][nc];
                        grid[nr][nc] = 0;
                        st.push_back({nr, nc});
                    }
                }

                if (sum % k == 0) count++;
            }
        }

        return count;
    }
};