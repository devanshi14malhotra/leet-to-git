class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int r=0, c=0;
        while (true){
            char ch = grid[r][c];
            grid[r][c] = 'X';
            int nr=r, nc=c;
            if (ch=='L') nc--;
            else if (ch=='R') nc++;
            else if (ch=='U') nr--;
            else nr++;
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc]=='X') break;
            r = nr;
            c = nc;
        }
        return {r,c};
    }
};