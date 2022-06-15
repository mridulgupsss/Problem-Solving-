class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        int idx=0;
        for(auto vec: edges){
            adj[vec[0]].push_back({vec[1], succProb[idx]});
            adj[vec[1]].push_back({vec[0], succProb[idx]});
            
            idx++;
        }
        
 priority_queue< pair<double, int >> pq;
        
        // prob, node 
        pq.push({1, start});
        vector<int> vis(n, 0);
        
        
        
        while(!pq.empty()){
            pair rem=pq.top();
            pq.pop();
        
            auto [prob, node]  = rem;
            
            if(vis[node]==1) continue;
            vis[node]=1;
            
            if(node==end) return prob;
            
            for(auto nbr : adj[node]){
                 if(vis[nbr.first]==0) pq.push({prob*nbr.second, nbr.first});
            }

            
        }
        
        return 0; 
    }
};