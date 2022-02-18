class StockSpanner {
public:
    vector<pair<int,int>> v; // price , ans
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int idx = v.size();
        if(idx==0){
            v.push_back({price, 1});
        }
        else{
            if(v[idx-1].first>price){
                v.push_back({price, 1});
            }
            else{
                int ans = 1+v[idx-1].second;
                int newIdx=idx-v[idx-1].second-1;
                while(newIdx>=0 && v[newIdx].first<=price){
                    ans+=v[newIdx].second;
                    newIdx=newIdx-v[newIdx].second;
                }
                
                v.push_back({price, ans});
            }
        }
        
        return v[v.size()-1].second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */