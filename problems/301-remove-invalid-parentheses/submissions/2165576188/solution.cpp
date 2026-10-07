class Solution {
public:
    bool isValid(string& s) {
        int balance = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') balance++;
            else if (s[i] == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }
        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                string current = q.front();
                q.pop();

                if (isValid(current)) {
                    result.push_back(current);
                    found = true;
                }

                if (found) continue; 

                for (int j = 0; j < current.size(); j++) {
                    if (current[j] != '(' && current[j] != ')') continue;

                    string next = current.substr(0, j) + current.substr(j + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if (found) break; 
        }

        return result;
    }
};