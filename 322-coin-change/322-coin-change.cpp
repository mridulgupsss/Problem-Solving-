class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int n = amount;
        int dp[n+1];
        for(int i=0;i<=n;i++) dp[i]=0;
        //
        for(int i=0; i<coins.size(); i++){
            int coin = coins[i];
            for(int j=coin; j<n+1; j++){
                int idx = j-coin;
               if(idx==0 || dp[idx]>0){
                if(dp[j]==0){
                   
                    dp[j]= dp[idx]+1;
                }
                else{
                    dp[j] =min(dp[j], dp[idx]+1);
                }
               }

            }
        }
        
        return (dp[n]==0 && amount>0)?-1:dp[n];
        
    }
};