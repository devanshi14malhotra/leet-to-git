class Solution {
public:
    int minRotations(string s) {
        int curr = 0;
        int tot = 0;
        for (int i=0; i<s.size(); i++){
            int tar = s[i]-'0';
            int diff = abs(tar-curr);
            int shorter = min (diff, 10-diff);
            tot +=shorter;
            curr=tar;
            
        }
        return tot;
    }
};