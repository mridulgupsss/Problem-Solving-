class Solution {
public:
    int change(int amount, vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(amount + 1, 0);
        dp[0]=1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=amount; j++)
            {
                int coin=arr[i];
               if(j>=coin)
               {
                   dp[j]+=dp[j-coin];
               }
                
                   
                
            }
        }
        return dp[amount];
    }
};