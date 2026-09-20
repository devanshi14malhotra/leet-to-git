class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int rev = 26 - (s[i] - 'a');  
            ans += rev * (i + 1);         
        }
        return ans;
    }
};