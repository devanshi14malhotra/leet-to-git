class Solution {
public:
    int countValidPrefixes(string s) {
        int zero=0;
        int one=0;
        int res=0;
        for (char c : s){
            if (c=='0') zero++;
            else one++;
            if (abs(zero-one)<=1)
                res++;
        }
        return res;
    }
};