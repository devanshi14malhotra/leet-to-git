class Solution {
public:
    int dfs(vector<string>& tokens) {
        string token = tokens.back();
        tokens.pop_back();

        if (token != "+" && token != "-" &&
             token != "*" && token != "/")
        {
            return stoi(token);
        }

        int right = dfs(tokens);
        int left = dfs(tokens);

        if (token == "+") {
            return left + right;
        } else if (token == "-") {
            return left - right;
        } else if (token == "*") {
            return left * right;
        } else {
            return left / right;
        }
    }

    int evalRPN(vector<string>& tokens) {
        return dfs(tokens);
    }
};