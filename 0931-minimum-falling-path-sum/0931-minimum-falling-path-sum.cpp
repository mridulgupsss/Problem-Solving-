class Solution {
public:
    int recursive(vector<vector<int>> &mat, int i, int j, int n , int m, vector<vector<int>> &dp){
        if( j<0 || j>=m) return INT_MAX;
         if(i==n-1) return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=mat[i][j] + min({recursive(mat, i+1, j-1, n, m, dp), recursive(mat, i+1, j, n, m, dp), recursive(mat, i+1, j+1, n, m, dp) });
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int ans = INT_MAX;
        int n=mat.size(); int m= mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int j=0;j<m;j++)
        {
            ans = min(ans,recursive(mat, 0, j, n, m, dp));
        }
        
          return ans;
    }
    
  
};