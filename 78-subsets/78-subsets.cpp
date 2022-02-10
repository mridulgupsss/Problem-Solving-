class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        int n=arr.size();
        
        int last=(1<<n)-1;
        vector<vector<int>> ans;
        for(int i=0; i<=last; i++)
        {
            int num=i; vector<int> small;
            for(int j=n-1; j>=0; j--){
                
                if((num&1)!=0){
                    // last bit on
                    small.insert(small.begin() ,arr[j]);
                }
          
                num>>=1;
                
            }
            ans.push_back(small);
        }
        
        return ans;
    }
};