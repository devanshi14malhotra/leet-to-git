class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;
        for (const string& op:operations){
            if (op=="+"){
                int top=stack.back();
                stack.pop_back();
                int newTop=top+stack.back();
                stack.push_back(top);
                stack.push_back(newTop);
            } else if (op=="D"){
                stack.push_back(2*stack.back());
            } else if (op=="C"){
                stack.pop_back();
            } else {
                stack.push_back(stoi(op));
            }
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }
};