class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()) return false;
        unordered_map<char,int> cs;
        unordered_map<char,int> ct;
        for (int i=0; i<s.length(); i++){
            cs[s[i]]++;
            ct[t[i]]++;
        }
        return cs==ct;
    }
};