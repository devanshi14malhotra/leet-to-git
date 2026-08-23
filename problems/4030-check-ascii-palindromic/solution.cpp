class Solution {
public:
    bool isPalindromic(string s) {
        string binary;
        for (char c : s){
            for (int i=7; i>=0; i--){
                int bit = (c>>i) & 1;
                if (bit==1) {
                    binary = binary + '1';
                } else {
                    binary = binary + '0';
                }
            }
        }
        int l=0;
        int r=binary.size()-1;
        while (l<r){
            if (binary[l] != binary[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};