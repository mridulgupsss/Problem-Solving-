class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans =0; int n = colors.size(); 
        int prev=0, curr=1;
        while(curr<n){
            if(colors[prev]!=colors[curr]){
                prev=curr;
                
            }
            else{
                if(neededTime[prev]<neededTime[curr]){
                    ans +=neededTime[prev];
                    prev=curr;
                    
                }
                else{
                    ans+=neededTime[curr];
                    
                }
            }
            
            curr++;
        }
        
        
        return ans;
        
    }
};