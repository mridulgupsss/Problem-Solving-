class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n= arr.size();
        vector<int> left(n);
        vector<int> right(n);
        int xorx=0;
        int xory=0;
        
        for(int i=0; i<n; i++){
            xorx^=arr[i];
            left[i]=xorx;
            
            xory^=arr[n-i-1];
            right[n-i-1]=xory;
        }  
        
        
        vector<int> ans ;
        for(int i=0; i<queries.size(); i++){
            int total_xor = right[0];
            int a=queries[i][0];
            int b=queries[i][1];
            
            if(a!=0){
               total_xor^=left[a-1];      
            }
            
            if(b!=n-1){
                total_xor^=right[b+1];
            }
            
            ans.push_back(total_xor);
        }
        
        return ans;
    }
};