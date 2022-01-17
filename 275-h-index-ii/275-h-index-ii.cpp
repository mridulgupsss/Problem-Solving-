class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n=arr.size();
        int lo=0, hi=n-1, potential_ans=0;// =0 to handle case [0];
        while(lo<=hi){
            int mid=(lo+hi)/2;
            
            int cnt=n-mid;
            int val=arr[mid];
            
            if(val<cnt){
                lo=mid+1;
            }
            else{
                potential_ans=cnt;
                hi=mid-1;
            }
            
        }
        
        return potential_ans;
    }
};