class Solution {
public:
    int titleToNumber(string str) {
       int ans =0; int factor=1;
        for(int i=str.size()-1; i>=0; i--){
            char ch =str[i];
            int num=ch-'A'+1;
            ans+=factor*1LL*num;
            factor=factor*1LL*26;
        }
        
        return ans;
    }
};