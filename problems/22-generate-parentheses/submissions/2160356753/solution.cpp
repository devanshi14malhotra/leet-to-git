class Solution {
public:
    vector<string> result;

    void backtrack(string current, int openCount, int closeCount, int n) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (openCount < n) {
            backtrack(current + "(", openCount + 1, closeCount, n);
        }

        if (closeCount < openCount) {
            backtrack(current + ")", openCount, closeCount + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        result.clear();
        backtrack("", 0, 0, n);
        return result;
    }
};