class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n =gas.size(); int s=0;
        for(auto val: gas){
            s+=val;
        }
        for(auto val: cost){
            s-=val;
        }
        if(s<0) return -1;
        
        int fuel=0, idx=0;
        for(int i=0; i<n; i++){
             fuel+=gas[i]-cost[i];
            if(fuel<0){
                fuel=0;
                 idx=i+1;
            }
        }
        
        return idx;
        
    }
};