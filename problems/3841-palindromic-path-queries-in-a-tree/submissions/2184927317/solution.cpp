class Solution {
public:
    int T = 0, N;
    vector<vector<int>> g, up;
    vector<int> in, out, dep, b;

    void add(int i, int x) { for (; i <= N; i += i & -i) b[i] ^= x; }
    int get(int i) { int r = 0; for (; i; i -= i & -i) r ^= b[i]; return r; }
    void upd(int u, int x) { add(in[u], x); add(out[u] + 1, x); }

    void dfs(int u, int p) {
        in[u] = ++T; up[0][u] = p;
        for (int k = 1; k < 16; k++) up[k][u] = up[k-1][up[k-1][u]];
        for (int v : g[u]) if (v != p) dep[v] = dep[u] + 1, dfs(v, u);
        out[u] = T;
    }

    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int k = 0; k < 16; k++) if ((dep[u] - dep[v]) >> k & 1) u = up[k][u];
        if (u == v) return u;
        for (int k = 15; k >= 0; k--)
            if (up[k][u] != up[k][v]) u = up[k][u], v = up[k][v];
        return up[0][u];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        N = n; g.resize(n); up.assign(16, vector<int>(n));
        in.resize(n); out.resize(n); dep.resize(n); b.assign(n + 2, 0);
        for (auto& e : edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        dfs(0, 0);
        for (int i = 0; i < n; i++) upd(i, 1 << (s[i] - 'a'));

        vector<bool> ans;
        for (auto& q : queries) {
            int u, v; char c;
            if (q[0] == 'u') {
                sscanf(q.c_str(), "update %d %c", &u, &c);
                upd(u, (1 << (s[u] - 'a')) ^ (1 << (c - 'a')));
                s[u] = c;
            } else {
                sscanf(q.c_str(), "query %d %d", &u, &v);
                int m = get(in[u]) ^ get(in[v]) ^ (1 << (s[lca(u, v)] - 'a'));
                ans.push_back(!(m & (m - 1)));
            }
        }
        return ans;
    }
};