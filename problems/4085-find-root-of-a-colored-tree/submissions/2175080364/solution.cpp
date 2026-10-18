class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int> indeg(n,0), deg(n,0), code(n);
        for (int i=0; i<n; i++){
            if (colors[i]=='R') code[i]=0;
            else if (colors[i]=='B') code[i]=1;
            else code[i] = 2;
        }
        for (int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            deg[u]++;
            deg[v]++;
            if (code[u] == code[v]) return -1;
            if ((code[u] + 1) % 3 == code[v]) indeg[v]++;
            else indeg[u]++;
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                if (root != -1) return -1;
                root = i;
            } else if (indeg[i] != 1) {
                return -1;
            }
        }
        if (root == -1 || deg[root] > 2) return -1;
        return root;
    }
};