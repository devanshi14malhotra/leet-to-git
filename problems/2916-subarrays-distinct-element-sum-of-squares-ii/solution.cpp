class Solution {
public:
    const long long MOD = 1000000007;
    vector<long long> sum1, sum2, lazy; 
    int n;

    void apply(int node, int len, long long v) {
        sum2[node] = (sum2[node] + 2 * v % MOD * sum1[node] + (long long)len * v % MOD * v) % MOD;
        sum1[node] = (sum1[node] + (long long)len * v) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = (l + r) / 2;
            apply(node * 2, mid - l + 1, lazy[node]);
            apply(node * 2 + 1, r - mid, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, r - l + 1, 1);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);
        sum1[node] = (sum1[node * 2] + sum1[node * 2 + 1]) % MOD;
        sum2[node] = (sum2[node * 2] + sum2[node * 2 + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum1.assign(4 * n, 0);
        sum2.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int x = nums[j];
            update(1, 0, n - 1, last[x] + 1, j);
            last[x] = j;
            ans = (ans + sum2[1]) % MOD; 
        }

        return (int)ans;
    }
};