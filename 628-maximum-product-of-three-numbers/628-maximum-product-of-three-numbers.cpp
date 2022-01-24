class Solution {
public:
    int maximumProduct(vector<int>& arr) {
        int mx1=INT_MIN, mx2=INT_MIN, mx3=INT_MIN, mn1=INT_MAX, mn2=INT_MAX;
        for(auto val: arr){
            if(val>=mx1){
                mx3=mx2;
                mx2=mx1;
                mx1=val;
            }
            else if(val>mx2){
                mx3=mx2;
                mx2=val;
            }
            else if(val>=mx3){
                mx3=val;
            }
        }
        
        for(auto val: arr){
            if(val<=mn1){
                mn2=mn1;
                mn1=val;
            }
            else if(val<=mn2){
                mn2=val;
            }
        }
        
        
       return max(mx1*mx2*mx3, mx1*mn1*mn2);
    }
};