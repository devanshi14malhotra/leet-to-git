class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> freq;
        for (int p : planks) freq[p]++;

        vector<int> vals;
        for (auto& kv : freq) vals.push_back(kv.first);
        sort(vals.begin(), vals.end());
        int m = vals.size();

        unordered_map<long long, long long> best;

        for (int i = 0; i < m; i++) {
            best[vals[i]] += freq[vals[i]];
            best[2LL * vals[i]] += freq[vals[i]] / 2;

            for (int j = i + 1; j < m; j++) {
                long long h = (long long)vals[i] + vals[j];
                best[h] += min(freq[vals[i]], freq[vals[j]]);
            }
        }

        long long ans = 0;
        for (auto& kv : best) ans = max(ans, kv.second);
        return (int)ans;
    }
};