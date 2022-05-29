class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), cnt(n,1);
        dp[0]=cnt[0]=1;
        
        for(int i=1; i<n; i++){
            int len=1;
            for(int j=i-1; j>=0; j--){
                
                if(arr[j]<arr[i]  && dp[j]+1>=len){
                    
                   
                    if(dp[j]+1>len){
                        cnt[i]=cnt[j];
                    }
                    else{ // dp[j]+1==len
                        cnt[i]+=cnt[j];
                    }
                    
                    len=dp[j]+1;
                     dp[i]=len;
                }
            }
        }
            int ans; int mx=0;
            for(int i=0; i<n; i++){
                if(dp[i]>mx){
                    ans=cnt[i];
                    mx=dp[i];
                }
                else if (dp[i]==mx){
                    ans+=cnt[i];
                }
            }
        
            return ans;
        
    }
};