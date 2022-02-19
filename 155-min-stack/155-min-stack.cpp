class MinStack {
public:
    stack<long> st;
    long mn;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mn=val;
        }
        else{
            if(val>=mn){
                st.push(val);
            }
            else{
                st.push(2*1LL*val-mn);
                mn=val;
            }
        }
    }
    
    void pop() {
        if(st.top()>=mn) st.pop();
        else {
            mn= 2*1LL*mn-st.top();
            st.pop();
        }
    }
    
    int top() {
       if(st.top()>=mn) return st.top();
        else return mn;
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */