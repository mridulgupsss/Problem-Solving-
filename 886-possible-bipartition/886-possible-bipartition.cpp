class Solution {
public:
    
bool bfs(vector<vector<int>>& adj, vector<int> &color, int node){
        queue<pair<int, int>> q;
        pair<int, int> p = {node, 0};
    q.push(p);
        while(!q.empty()){
            pair<int, int> rem = q.front(); q.pop();
            int col = rem.second;
            int ver = rem.first;
            if(color[ver]!=-1){
                if(color[ver]!=col) return false;
                continue;
            }
            else{
                 color[ver]=col;
                for(int i=0; i<adj[ver].size(); i++){
                   if(color[adj[ver][i]]==-1) q.push({adj[ver][i], (col==0?1:0)}) ;
                }
            }
        }
        
        return true;
}
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto vec: dislikes){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
            
        }
        
        vector<int> color(n+1, -1);
        for(int i=1; i<=n; i++){
            if(color[i]==-1){
                if(bfs(adj, color, i)==false )return false;
            }
        }
        
        return true;
        
    }
};