class StockSpanner {
public:
    stack<pair<int, int> >st; // price , idx
    int idx;
    StockSpanner() {
        idx=-1;
    }
    
    int next(int price) {
               idx++;

        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int prev;
        if(st.empty()) prev=-1;
        else{
            prev =  st.top().second;
        }
        
        st.push({price,idx});
        return idx-prev;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */