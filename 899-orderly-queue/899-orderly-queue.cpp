class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n=s.length();
        if(k>1){
            sort(s.begin(), s.end());
            return s;
        }
        // else 
        string ans=s;
        for(int i=0; i<n; i++){
             s = s.substr(1, n-1)+ s[0];
            ans=min(ans, s);
        }
        return ans;
    }
};