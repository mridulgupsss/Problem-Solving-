class Solution {
public:
    int maxCoins(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int gap=0; gap<n; gap++)
        {
            for(int i=0, j=gap; i<n-gap; i++, j++)
            {
                if(gap==0){
                    dp[i][j]=arr[i];
                    if(i>=1) dp[i][j]*=arr[i-1];
                    if(i<=n-2) dp[i][j]*=arr[i+1];
                }
                else
                {
                    int maxx=0;
                    for(int k=i; k<=j; k++)
                    {
                        int curr=arr[k];
                        if(i>=1)curr*=arr[i-1];
                        if(j<=n-2) curr*=arr[j+1];
                        
                        int left=0, right=0;
                        if(k!=i){
                            left=dp[i][k-1];
                        }
                        if(k!=j){
                            right=dp[k+1][j];
                        }
                        
                        int total= left + curr + right;
                        maxx=max(maxx, total);
                    }
                    dp[i][j]=maxx;
                }
            }
        }
        return dp[0][n-1];
        
        
    }
};