class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0;
        for(auto ch: s){
            ans=ans^(ch-'a');
        }
        for(auto ch: t){
            ans=ans^(ch-'a');
        }
        return ans+'a';
    }
};