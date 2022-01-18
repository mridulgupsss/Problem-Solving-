class Solution {
public:
    int fun(vector<int>& arr, int k, int mid){
         int bouq=0, flow=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>mid) flow=0;
            else{
                flow++;
                if(flow==k){
                    flow=0;
                    bouq++;
                }
            }
        }
        
        return bouq;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size(), ans;
        if(m > n/k) return -1;
        
        int lo=1, hi=1e9;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(fun(arr, k, mid)>=m){
                ans=mid; // potential  // m=current days we took
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
            
            
        }
        return ans;
    }
};