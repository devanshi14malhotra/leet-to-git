class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> p(n+1, true);
        vector<int> ans;
        long long sum = 0;
        for (int i=2; i<=n; i++){
            if (!p[i]) continue;
            if (sum + i > s) break;
            sum += i;
            ans.push_back(i);
            for (long long j = (long long)i*i; j<= n; j+=i)
                p[j] = false;
        }
        return ans;
    }
};