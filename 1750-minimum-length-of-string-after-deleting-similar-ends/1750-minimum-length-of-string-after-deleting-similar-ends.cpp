class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0; int j=n-1;
        int ans =n;
        while(i<j){
            if(s[i]!=s[j]) break;
            else{
                char a = s[i];
                char b = s[j];
                
                while(i<j && s[i]==a){
                    ans--;
                    i++;
                }
                while(i<=j && s[j]==b){  // i<=j is very important
                     j--;
                    ans--;
                }
            }

        }
        return ans;
    }
};