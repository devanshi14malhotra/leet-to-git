class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int m = invocations.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<bool> suspicious(n, false);
        vector<int> bfsQueue(n);
        int head = 0, tail = 0;

        suspicious[k] = true;
        bfsQueue[tail++] = k;

        while (head < tail) {
            int u = bfsQueue[head++];
            for (int idx = 0; idx < (int)adj[u].size(); idx++) {
                int v = adj[u][idx];
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    bfsQueue[tail++] = v;
                }
            }
        }
        bool canRemove = true;
        for (int i = 0; i < m && canRemove; i++) {
            int a = invocations[i][0];
            int b = invocations[i][1];
            if (suspicious[b] && !suspicious[a]) {
                canRemove = false;
            }
        }

        vector<int> result;
        result.reserve(n);
        if (!canRemove) {
            for (int i = 0; i < n; i++) result.push_back(i);
        } else {
            for (int i = 0; i < n; i++) {
                if (!suspicious[i]) result.push_back(i);
            }
        }

        return result;
    }
};