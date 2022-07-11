class Solution {
public:
    
    
    unordered_map<int,int>visited,SILENT;
    
    
    int dfs(unordered_map<int,vector<int>>&graph,vector<int>& quiet,int i)
    {
        int a=INT_MAX;
        
        for(auto x:graph[i])
        {
            if(!visited[x])
            {
               a=std::min(a,dfs(graph,quiet,x));
            }
            else
            {
                a=std::min(a,visited[x]);
            }
            
        }
        
        return visited[i]=std::min(a,quiet[i]+1);
        
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        vector<int>ans;
        unordered_map<int,vector<int>>graph;
        
        
        for(int i=0;i<quiet.size();i++)
        {
            SILENT[quiet[i]]=i;
        }
        
        
        for(auto x:richer)
        {
            graph[x[1]].push_back(x[0]);
        }
        
        for(int i=0;i<quiet.size();i++)
        {
            if(!visited[i])
            {
                visited[i]=dfs(graph,quiet,i);
            }
            ans.push_back(SILENT[visited[i]-1]);
        }
        return ans;
   
    }
};