class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(n, vector<int>(m, 0));
           for(int i=n-1; i>=0; i--){
               for(int j=m-1; j>=0; j--){
                   if(i==n-1 && j==m-1){
                       dp[i][j] = 1;
                       
                   }
                   else if(j==m-1){
                       dp[i][j]=dp[i+1][j];
                       
                   }
                   else if(i==n-1){
                       dp[i][j]=dp[i][j+1];
                   }
                   else{
                       dp[i][j]=dp[i][j+1] + dp[i+1][j];
                   }
               }
           }
           
           return dp[0][0];
       } 
    
};