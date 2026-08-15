class Solution {
public:
    bool isValid(string s) {
        stack<char> myst;
        for (char c:s){
            if (c=='(' || c=='{' || c=='[') myst.push(c);
            else {
                if (myst.empty()) return false;
                char top=myst.top();
                if ((c==')' && top!='(') || (c=='}' && top!='{') || (c==']' && top!='[')) return false;
                myst.pop();
            }
        }
        return myst.empty();
    }
};