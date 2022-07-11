class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        queue<string> q;
		
		// this stores indegree of each recipes
        unordered_map<string,int> inorder;
		//stores all the relations of graph whre it's key will be some supply/recipe need for some recipe
        unordered_map<string,vector<string>> adj;
        vector<string> ans;
		
		//push every supply element in queue as it's indegree will be already zero
        for(string s: supplies) q.push(s);
        
		
        for(int i=0; i< recipes.size();i++){
            for(string str: ingredients[i]){
			//we are increasing indegree of each recipe according to no. of things needed for it
                inorder[recipes[i]]++;
			//we are pushing each recipe corresponding to ingredient 
                adj[str].push_back(recipes[i]);
            }
        }
        
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(string s: adj[curr]){
			
			//checking if indegree of recipe & pushing it in ans and que as it can be ingredient for some other recipe
                if(--inorder[s]==0){
                    ans.push_back(s);
                    q.push(s);
                }
            }
        }
        return ans;
    }
};