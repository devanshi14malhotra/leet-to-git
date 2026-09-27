class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stack;
        stack.push_back("");

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '(') {
                stack.push_back("");
            } else if (c == ')') {
                string top = stack.back();
                stack.pop_back();

                reverse(top.begin(), top.end());

                stack.back() += top;
            } else {
                stack.back() += c;
            }
        }

        return stack.back();
    }
};