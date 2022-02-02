class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans ;
        int k=p.size();
        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;
        for(int i=0; i<p.size(); i++){
            mp1[p[i]]++;
        }
        for(int i=0; i<k-1; i++){
            mp[s[i]]++;
        }
        
        for(int i=k-1; i<s.length(); i++){
            // acquire in map
            mp[s[i]]++;
            
            //check ans
            if(mp==mp1){
                ans.push_back(i-k+1);
            }
            
            // release from map
            if(mp[s[i-k+1]]==1){
                mp.erase(s[i-k+1]);
            }
            else
            mp[s[i-k+1]]--;
        }
        
    
        
        
        
        
        
        return ans;
    }
};