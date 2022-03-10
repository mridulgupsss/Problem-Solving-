class Solution {
public:
    bool helper(unordered_map<int, vector<int>> &mp, int src, int dst, vector<bool> &vis){
        if(src==dst) return true;
        vis[src]=true;
        for(int i=0; i<mp[src].size(); i++){
            if(vis[mp[src][i]]==false){
                if(helper(mp, mp[src][i], dst, vis)==true) return true;
            }
        }
        return false;
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
     vector<bool> vis(n,false);
        
        unordered_map<int, vector<int>> Adjlist;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            Adjlist[u].push_back(v);
            Adjlist[v].push_back(u);
        }
       return helper(Adjlist, src, dst, vis); 
    }
};





