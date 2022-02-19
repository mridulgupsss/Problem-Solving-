class MinStack {
public: // storing gap strategy
    stack<long> st;
    long mn;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);  // storing gap
            mn=val;
        }
        else{
              st.push(val-mn);
            if(val<mn){
                mn=val;
            }
        }
    }
    
    void pop() {
        
        if(st.top()<0){
           mn=mn-st.top(); 
            
        }
        st.pop();
    }
    
    int top() {
       if(st.top()>=0) return mn+st.top();
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