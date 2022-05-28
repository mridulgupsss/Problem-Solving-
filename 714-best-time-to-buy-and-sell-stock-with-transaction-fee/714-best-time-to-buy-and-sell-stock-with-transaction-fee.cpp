class Solution {
public:
    
    // striver very important

    int maxProfit(vector<int>& arr, int fee) {
        int n =arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2));
        dp[n][1]=dp[n][0] = 0;
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<2; buy++){
        long profit=0;
        if(buy){
            // cant sell , buy or dont buy 
            profit =  max(dp[idx+1][0] -arr[idx] , dp[idx+1][1]);
        }
        else{
            // cant buy, sell or dont sell
             profit =  max(arr[idx] -fee +dp[idx+1][1], dp[idx+1][0]);
        }
                
                dp[idx][buy]=profit;
            }
        }
        
        return dp[0][1];
    }
};