class Solution {
public:  // 3D DP pepcoding scramble strings video 
    bool isScramble(string s1, string s2) {
        int n=s1.length();
        
      vector<vector<vector<bool>>>dp(n, vector<vector<bool>>(n, vector<bool>(n+1)));
        for(int len=1; len<=n; len++)
        {
            for(int i=0; i<=n-len; i++)
            {
                for(int j=0; j<=n-len; j++){
                    
                    if(len==1) dp[i][j][len]=s1[i]==s2[j];
                    else{
                        for(int cut=0; cut<=len-2 && !dp[i][j][len]; cut++)
                        {
                            dp[i][j][len]=( ( (dp[i][j][cut+1]) && (dp[i+cut+1][j+cut+1][len-cut-1]) )  ||  ( (dp[i][j+len-cut-1][cut+1]) && (dp[i+cut+1][j][len-cut-1]) ) ); 
                        }
                    }
                }
            }
        }
        
        return dp[0][0][n];
        
        
    }
};