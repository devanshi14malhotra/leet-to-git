class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
    }
    
    void push(int value) {
        st.push(value);
        if (minst.empty()){
            minst.push(value);
        } else {
            value=min(value,minst.top());
            minst.push(value);
        }
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */