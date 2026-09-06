class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int t=0;
        for (int i=0; i<n; i++){
            if (s[i] == s[(i+1)%n]) t++;
        }
        if (k==t) return n-t;
        if (k==t-1) return t;
        return 0;
    }
};