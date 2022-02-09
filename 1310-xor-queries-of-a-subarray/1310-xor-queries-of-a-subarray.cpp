class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n= arr.size();
        vector<int> left(n);

        int xorx=0;
        
        
        for(int i=0; i<n; i++){
            xorx^=arr[i];
            left[i]=xorx;
            

        }  
        
        
        vector<int> ans ;
        for(int i=0; i<queries.size(); i++){
        
            int a=queries[i][0];
            int b=queries[i][1];
            
            if(a!=0){
               ans.push_back(left[a-1]^left[b]);      
            }
            
            else{
                ans.push_back(left[b]);
            }
            
        }
        
        return ans;
    }
};