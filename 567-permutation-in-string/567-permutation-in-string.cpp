class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();
        if(n1>n2) return false;
        unordered_map<char,int> mp;
        unordered_map<char ,int> mp2;
        for(auto ch :s1){
            mp[ch]++;
        }
        for(int i=0; i<n1-1; i++){
            mp2[s2[i]]++;
        }
        
      for(int i=0, j=n1-1; j<n2; j++, i++){
          // acquire 
          mp2[s2[j]]++;
          
          // ans
          if(mp2==mp){
              return true;
          }
          
          // release
          if(mp2[s2[i]]>1) mp2[s2[i]]--;
          else mp2.erase(s2[i]);
      }
        
        return false;
    }
};