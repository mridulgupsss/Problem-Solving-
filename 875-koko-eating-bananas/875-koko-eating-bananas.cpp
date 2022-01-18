class Solution {
public:
    int fun(vector<int>& arr, int val){
        int cnt=0;
        for(auto v : arr){
            if(v%val==0){
                cnt+=v/val;
            }
            else{
                cnt+=v/val +1;
            }
            
          
        }
        
          return cnt;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int maxx=-1, ans;
        for(auto val: arr){
            maxx=max(maxx, val);
        }
        int lo=1, hi=maxx;
        while(lo<=hi){
            int m=(lo+hi)/2;
            if(fun(arr, m)>h){
                lo=m+1;
            } 
            else{
                ans=m; // potential ans
                hi=m-1;
                
            }
        }
        
        return ans;
    }
};