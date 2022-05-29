class Solution {
public:
    static bool cmp(string a, string b){
        return a.size() < b.size();
    }
    
    bool check(string &a, string &b){
        if(a.size()+1!=b.size()) return false;
        else {
            int i=0, j=0;
            while(j<b.size()){
                if(a[i]==b[j]){
                    i++;
                    j++;
                }
                else j++;
            }
            
            if(i==a.size()) return true;
            return false;
        }
    }
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        int n =arr.size();
        vector<int>dp(n,1);
        int ans=dp[0];  
        for(int i=1; i<n; i++)
        {
            int maxx=0; 
            for(int j=0; j<i; j++)
            {
                if(check(arr[j], arr[i])){
                    maxx=max(maxx, dp[j]);
                    
                }
                
            }
            dp[i]=maxx+1;
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};