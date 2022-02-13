class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0; int j=n-1;
        int ans =n;
        while(i<=j){
            if(s[i]!=s[j]) break;
            else{
                char a = s[i++];
                char b = s[j--];
                ans-=2;
                
                while(i<=j && s[i]==a){
                    ans--;
                    i++;
                }
                while(i<=j && s[j]==b){
                     j--;
                    ans--;
                }
            }

        }
        return ans==-1?1:ans;
    }
};