class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& arr, int left, int right) {
        int prev =-1, ans=0;
        int n = arr.size();
        int prev_count=0;
        int i=0;
        while(i<n){
            if(arr[i]<left){
                ans+=prev_count;
            }
            else if(arr[i]>right){
                prev=i;
                prev_count=0;
                
            }
            else{
                prev_count=i-prev;
                ans+=prev_count;
            }
            
            
            i++;
        }
        
        return ans;
    }
};