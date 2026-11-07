class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int a=-1, ab=-1, abc=-1;
        for (int r=0; r<s.size();r++){
            if (s[r]=='a') a=r;
            else if (s[r]=='b') ab=a;
            else abc = ab;
            ans += r-abc;
        }
        return ans;
    }
};