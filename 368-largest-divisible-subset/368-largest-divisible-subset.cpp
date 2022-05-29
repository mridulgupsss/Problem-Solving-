class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
            int n =arr.size();
            vector<int> dp(n,1);
            vector<int> traverse_back(n,-1);
            for(int i=1;i<n;i++){
                int val=0;
                for(int j=i-1; j>=0; j--){
                    if(arr[i]%arr[j]==0 && dp[j]>val){
                        val=dp[j];
                        traverse_back[i]=j;
                    }
                }
                
                dp[i]=val+1;
            }

            int mx=0; int idx=-1;
            for(int i=0; i<n; i++){
                if(dp[i]>mx){
                    mx=dp[i];
                    idx=i;
                }
            }
      vector<int> ans;
      
        while(idx>=0){
            ans.push_back(arr[idx]);
            idx=traverse_back[idx];
        }
            
            return ans;
        }
    
    
};