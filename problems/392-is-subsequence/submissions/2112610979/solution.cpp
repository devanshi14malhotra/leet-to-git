class Solution {
public:
    bool isSubsequence(string s, string t) {
        return rec(s,t,0,0);
    }
    bool rec(string& s, string& t, int i, int j){
        if (i==s.size()) return true;
        if (j==t.size()) return false;
        if (s[i]==t[j]){
            return rec(s,t,i+1,j+1);
        }
        return rec(s,t,i,j+1);
    }
};