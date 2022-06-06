class Solution {
public:
    // https://www.youtube.com/watch?v=tCnpCc4kgcs
    int minDeletions(string s) {
        map<char, int> mp;  int ans =0;
        for(auto ch : s){
            mp[ch]++;
        }
        vector<int> f;
        for(auto it: mp){
            f.push_back(it.second);
            
            
        }
        set<int> st;
        for(auto val: f){
            if(st.find(val)==st.end()){
                st.insert(val);
            }
            else{
                ans++;
                for(int i=val-1; i>=1 ; i--){
                   if(st.find(i)==st.end()){
                      st.insert(i);
                      break;
                             }
                    ans++;  
                }
                
              
            }
        }
        
        return ans ;
    
    }
};