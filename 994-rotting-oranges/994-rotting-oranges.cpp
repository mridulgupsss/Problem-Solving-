class Solution {
public:

     int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
         int fresh=0;
        queue<pair<int, int>> q;
        int i=0;
        for(auto vec: grid){
            int j=0;
            for(auto val : vec){
                if(val==2){
                    pair<int, int> pp = {i, j};
                    q.push(pp);
                    
                }
                else if(val==1) fresh++;
                j++;
            }
            i++;
        }
        
        // bfs : 
        
         vector<int> dir={-1,0,1,0,-1};
        int ans =0;
        while(q.size()>0){
          int sz=q.size();
          while(sz--){
            pair<int, int> rem = q.front(); q.pop();     
            for(int idx=0; idx<4; idx++){
                int new_i = rem.first +dir[idx];
                int new_j = rem.second +dir[idx+1];
                
                if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && grid[new_i][new_j]==1){
                    grid[new_i][new_j]=2;
                    pair<int, int> new_pp = {new_i, new_j};
                    q.push(new_pp);
                    fresh--;
                }
            }
        }

            ans++; 
    }
        if(fresh>0) return -1;
        if (ans==0) return 0;
        return --ans;
            
            
        }
    
};