class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack;
        int res=0;
        for (const string& op:operations){
            if (op=="+"){
                int top=stack.top();
                stack.pop();
                int prevTop=stack.top();
                int newTop=top+prevTop;
                stack.push(top);
                stack.push(newTop);
                res+=newTop;
            } else if (op=="D"){
                stack.push(2*stack.top());
                res+=stack.top();
            } else if (op=="C"){
                res-=stack.top();
                stack.pop();
            }
            else {
                stack.push(stoi(op));
                res+=stack.top();
            }
        }
        return res;
    }
};