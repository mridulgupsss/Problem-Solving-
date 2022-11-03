class Solution {
public:
    int recursive(vector<vector<int>> &mat, int i, int j, int n , int m, vector<vector<int>> &dp){
        // if( j<0 || j>=m) return INT_MAX;
        //  if(i==n-1) return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=mat[i][j] + min({recursive(mat, i+1, j-1, n, m, dp), recursive(mat, i+1, j, n, m, dp), recursive(mat, i+1, j+1, n, m, dp) });
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int ans = INT_MAX;
        int n=mat.size(); int m= mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // base case
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(i==n-1) dp[n-1][j]=mat[n-1][j];
            else if(j!=0 && j!=m-1){
                dp[i][j]=mat[i][j]+min({dp[i+1][j],dp[i+1][j+1], dp[i+1][j-1]});
            }
            else if(j==0){
                dp[i][j]=mat[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
            else if(j==m-1){
                dp[i][j]=mat[i][j]+min(dp[i+1][j],dp[i+1][j-1]);
            }
            
            

        }
    }
        
        for(int i=0; i<m; i++){
            ans=min(dp[0][i], ans);
        }
        return ans;
        
   
   
    
    }
    
  
};