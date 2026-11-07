class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        int last = -1;
        for (int r = 0; r<n; r++){
            if (r>=2 && s[r-2]=='a' && s[r-1]=='b' && s[r]=='c'){
                last = r-2;
            }
            ans += r-last;
        }
        return ans;
    }
};