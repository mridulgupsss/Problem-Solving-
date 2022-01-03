class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        int dp[n+1][m+1];
        for(int i=n; i>=0; i--)
        {
            for(int j=m; j>=0; j--)
            {
                if(i==n) dp[i][j]=0;
                else if(j==m) dp[i][j]=0;
                else {
                    if(text1[i]==text2[j])
                    {
                        dp[i][j]=dp[i+1][j+1] +1;
                        
                    }
                    else{
                        dp[i][j]=max(dp[i][j+1], dp[i+1][j]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};