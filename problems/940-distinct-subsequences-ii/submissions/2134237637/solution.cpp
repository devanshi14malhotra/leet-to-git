class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> contrib(26, 0); 
        long long dp = 0;

        for (char ch : s) {
            int c = ch - 'a';
            long long added = (dp + 1) % MOD;      
            long long newDp = ((dp + added - contrib[c]) % MOD + MOD) % MOD;
            contrib[c] = added;
            dp = newDp;
        }

        return (int)dp;
    }
};