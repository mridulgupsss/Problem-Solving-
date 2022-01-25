class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int st=-1, end=-2, n=arr.size(), left_max=arr[0], right_min=arr[n-1];
        for(int i=1; i<n; i++){
            if(arr[i]<left_max) end=i;
            if(arr[n-i-1]>right_min) st=n-i-1;
            
            left_max=max(left_max, arr[i]);
             right_min=min(right_min, arr[n-1-i]);
        }
        
        return end-st+1;
    }
};