class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid[0].size();
        vector<int> ans(m);
        int n=grid.size();
        for(int ball=0; ball<m; ball++){
            int col=ball;
            for(int i=0; i<n; i++){
                int next_col=col+grid[i][col];
                // curr block grid[i][col];
                if(next_col<0 || next_col==m || grid[i][col]+grid[i][next_col]==0){
                    ans[ball]=-1;
                    break;
                    
                }
                else{

                    col=next_col;
                   ans[ball]=col;
                }
                
            }
        }
        
        return ans;
        
    }
};