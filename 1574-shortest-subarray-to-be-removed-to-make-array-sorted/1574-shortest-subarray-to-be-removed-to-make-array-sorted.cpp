class Solution {
public:  // Must see its discusss section alot of approaches : 
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int l=0, r=n-1;
        while(l<n-1){
            if(arr[l]<=arr[l+1]) l++;
            else break;
        }
        
        if(l==n-1) return 0;
        
        while(r>0){
            if(arr[r]>=arr[r-1]) r--;
            else break;
        }
        
        int i=0, j=r;
        int ans=min(n-l-1, r);  // very imortant ;
        while(i<=l && j<n){
            if(arr[i]<=arr[j]){
                ans=min(ans, j-i-1);
                i++;
            }
            else{
                j++;
            }
        }
        
        return ans;
        
    }
};