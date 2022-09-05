class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0]>k) return k;
        int lo=0, hi=arr.size()-1; int idx=-1;
        while(lo<=hi){
            int mid =(lo+hi)>>1;
            if(arr[mid]-mid-1<k){
                idx=mid;
                lo=mid+1;
                
            }
            else if(arr[mid]-mid-1>k) hi=mid-1;
            else{
                hi=mid-1;
            }
        }
        
        return arr[idx]+(k-(arr[idx]-1-idx)); // k+idx+1 finally 
    }
};