class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int best = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
                if (depth > best) best = depth;
            } else if (s[i] == ')') {
                depth--;
            }
        }

        return best;
    }
};