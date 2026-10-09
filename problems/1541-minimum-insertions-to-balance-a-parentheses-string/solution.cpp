class Solution {
public:
    int minInsertions(string s) {
        int need = 0;    
        int inserts = 0;   

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (need % 2 == 1) {
                    inserts++;
                    need--;
                }
                need += 2;
            } else {
                need--;
                if (need < 0) {
                    inserts++;
                    need = 1;
                }
            }
        }

        return inserts + need;
    }
};