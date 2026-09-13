class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> temp(n, vector<int>(n));
        // ls row i by rs[i]
        for (int i=0; i<n; i++){
            int shift = rowShift[i] % n;
            for (int j=0; j<n; j++){
                int newcol = (j - shift % n + n) % n;
                temp[i][newcol] = grid[i][j];
            }
        }
        vector<vector<int>> res(n, vector<int>(n));
        // us col j by cs[j]
        for (int j=0; j<n; j++){
            int shift = colShift[j] % n;
            for (int i=0; i<n; i++){
                int newrow = (i - shift % n + n) % n;
                res[newrow][j] = temp[i][j];
            }
        }
        return res;
    }
};