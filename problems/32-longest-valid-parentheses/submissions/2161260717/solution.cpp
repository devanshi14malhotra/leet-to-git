class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        stack.push_back(-1); 

        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else {
                stack.pop_back();

                if (stack.empty()) {
                    stack.push_back(i); 
                } else {
                    int len = i - stack.back();
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};