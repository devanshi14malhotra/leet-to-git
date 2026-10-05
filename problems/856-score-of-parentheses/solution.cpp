class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> stack;
        stack.push_back(0); 

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(0); 
            } else {
                int innerScore = stack.back();
                stack.pop_back();

                int thisScore = (innerScore == 0) ? 1 : 2 * innerScore;

                stack.back() += thisScore; 
            }
        }

        return stack.back();
    }
};