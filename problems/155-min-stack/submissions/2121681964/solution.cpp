class MinStack {
public:
    long min;
    stack<long> st;

    MinStack() {
        
    }
    
    void push(int value) {
        if (st.empty()){
            st.push(0);
            min=value;
        } else {
            st.push(value-min);
            if (value<min) min=value;
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long pop=st.top();
        st.pop();
        if (pop<0) min=min-pop;
    }
    
    int top() {
        long top=st.top();
        return (top>0) ? (top+min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
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