class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (const string& c : tokens) {
            if (c == "+") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b + a);
            } else if (c == "-") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b - a);
            } else if (c == "*") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b * a);
            } else if (c == "/") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b / a);
            } else {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};