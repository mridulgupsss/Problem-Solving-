class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string &str=strs[0];
        string &str2=strs[strs.size()-1];
        
        for(int i=0; i<str.size();i++){
            if(str[i]!=str2[i]){
                return str.substr(0, i);
            }
        }
        
        return strs[0]; // faaltu
    }
};