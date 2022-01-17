class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int lo=0, hi=n-1, potential_ans;
        // boundary cases
        if(n==1) return arr[0];
        if(arr[n-1]<arr[n-2]) return arr[n-1]; // cases when minimum is at last 
        
            
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>arr[n-1]){
                    lo=mid+1;
            }   
            else if(arr[mid]<arr[n-1]){
                potential_ans=mid;
                hi=mid-1;
            }
    
            
           
        }
         
            return arr[potential_ans]; // faaltu
    }
};