class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { 
                low--;  
                high++; 
            }

            if (high < 0) return false; 

            if (low < 0) low = 0; 
        }

        return low == 0;
    }
};