class Solution {
public:
    vector<int> grayCode(int n) {
      if (n==1){
          vector<int> v;
          v.push_back(0);
          v.push_back(1);
          return v;
      }  
        
        vector<int> small = grayCode(n-1);
        vector<int> ans;
        for(auto val:small){
            ans.push_back(val);
        }
        for(int i=small.size()-1;i>=0;i--){
            ans.push_back((1<<n-1) + small[i]);
        }
        
        return ans;
            
        
        
        
    }
};