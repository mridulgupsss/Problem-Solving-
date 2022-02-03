class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int ans=INT_MIN, zero=0;
        int n=arr.size();
        int prod=1;
        for(int i=0; i<n; i++){
            if(arr[i]==0) {
                prod=1;
                zero=1;
            }
            else{
                prod*=arr[i];
                ans=max(ans, prod);
            }
        }
        
        prod=1;
        for(int i=n-1; i>=0; i--){
            if(arr[i]==0) prod =1;
            else{
                prod*=arr[i];
                ans=max(ans, prod);
            }
        }

        return ans<0 && zero==1?0:ans;
    }
};