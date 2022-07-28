class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;
        for(auto ch: s){
            mp[ch]++;
            
        }
        for(auto chh:t){
            mp[chh]--;
        }
        for(auto it: mp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};