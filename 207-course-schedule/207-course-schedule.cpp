class Solution {
public://
    // tech dose : detect cycle in directed graph
    
    bool dfs(vector<vector<int>> &adj, int node, vector<int> &vis, vector<int>&dfsvis){
        vis[node]=1;
        dfsvis[node]=1;
    

        for(auto val : adj[node]){
            if(vis[val]==-1){  
                if(!dfs(adj, val, vis, dfsvis)) return false;
            }
           else if(dfsvis[val]==1){return false;} 
        }
        dfsvis[node]=-1;
        return true;
    }
    
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(n);
        for(auto vec: prerequisites){
            adj[vec[0]].push_back(vec[1]);
        }
        vector<int> vis(n,-1);
        vector<int> dfsvis(n,-1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(!dfs(adj, i, vis, dfsvis)) return false;
            }
        }
        
        return true;
    }
};