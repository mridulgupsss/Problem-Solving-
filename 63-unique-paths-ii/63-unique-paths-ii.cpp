class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n =obstacleGrid.size();
        int m =obstacleGrid[0].size();
       vector<vector<long long>> dp(n, vector<long long>(m,  0));
           for(int i=n-1; i>=0; i--){
               for(int j=m-1; j>=0; j--){
                   if(obstacleGrid[i][j]==1){
                       dp[i][j]=0;
                   }
                   else if(i==n-1 && j==m-1){
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