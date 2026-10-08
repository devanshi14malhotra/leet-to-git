class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (depth > 0) result += '(';
                depth++;
            } else {
                depth--;
                if (depth > 0) result += ')';
            }
        }

        return result;
    }
};