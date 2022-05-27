class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int sum=0, n=arr.size();
        for(auto val :arr)
        {
            sum+=val;
        }
        if(target+sum<0 || (target+sum)%2!=0) return 0;
        int s1 = (target+sum)/2;
 vector<vector<int>>dp(n+1, vector<int>(s1+1));
            for(int i=0; i<=n; i++)
            {
                for(int j=0; j<=s1; j++)
                {
                    if(i==0 && j==0) dp[i][j]=1;
                     else if(j==0) {
                        if(arr[i-1]==0) dp[i][j]=2*dp[i-1][j];
                        else dp[i][j]=dp[i-1][j];
                    }
                    else if(i==0)dp[i][j]=0;
                    else
                    {
                       dp[i][j]=dp[i-1][j]; 
                        if(j>=arr[i-1]) dp[i][j]+=dp[i-1][j-arr[i-1]];
                    }
                }
            }
        
       return dp[n][s1];
    }
};