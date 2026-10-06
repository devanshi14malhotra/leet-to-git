class Solution {
public:
    int minAddToMakeValid(string s) {
        int openNeeded = 0;  
        int insertions = 0;  

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openNeeded++;
            } else { 
                if (openNeeded > 0) {
                    openNeeded--; 
                } else {
                    insertions++; 
                }
            }
        }

        return insertions + openNeeded;
    }
};