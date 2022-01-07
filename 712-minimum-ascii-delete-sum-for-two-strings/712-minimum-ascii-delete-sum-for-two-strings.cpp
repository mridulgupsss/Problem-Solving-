class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        int dp[n+1][m+1];
        for(int i=n; i>=0; i--)
        {
            for(int j=m; j>=0; j--)
            {
                if(i==n && j==m) dp[i][j]=0;
               else if(i==n){
                    dp[i][j]=s2[j]+dp[i][j+1];
                }
                else if(j==m)
                {
                    dp[i][j]=s1[i]+dp[i+1][j];
                }
                else{
                    if(s1[i]==s2[j]) dp[i][j]=dp[i+1][j+1];
                    else
                    {
                        dp[i][j]=min(s1[i]+dp[i+1][j], s2[j]+dp[i][j+1]);
                    }
                }
            }
        }
        
        return dp[0][0];
    }
};