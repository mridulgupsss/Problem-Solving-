class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto vec: flights){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        
 priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
        // cost, node, stops
        pq.push({0, src, 0});
        vector<int> discovery(n,INT_MAX);
        
        
        
        while(!pq.empty()){
            tuple rem=pq.top();
            pq.pop();
        

            
            auto [cost, node, stops]  = rem;
            
            if(stops > discovery[node]) continue;  // To Avoid TLE
		    discovery[node] = stops;

            
            if(stops>k+1) continue;
            if(node==dst) return cost;
            
            for(auto nbr : adj[node]){
                 pq.push({cost+nbr.second, nbr.first, stops+1});
            }

            
        }
        
        return -1;
        
        
        
        
    }
};