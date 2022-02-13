class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9 +7;
        int odd[n], even[n];
        even[0]=arr[0]%2==0?1:0;
        odd[0] =arr[0]%2==0?0:1;
        for(int i=1; i<n; i++){
            if(arr[i]%2==0){
                even[i]=(even[i-1]+1)%mod;
                odd[i]=odd[i-1];
            }
            else{
                even[i]=odd[i-1];
                odd[i]=(even[i-1]+1)%mod;
            }
        }
            
            
        int ans =0;
        for(auto val : odd){
            ans=(ans+val)%mod;
        }
        return ans;
    }
};