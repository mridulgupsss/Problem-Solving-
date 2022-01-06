class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        
        bool dp[n][n] ;int ans_i=0, ans_j=0;
        for(int gap=0; gap<n; gap++)
        {
            for(int i=0, j=gap; i<n-gap; j++, i++)
            {
                if(gap==0) dp[i][j]=true;
                else if(gap==1) {
                    if(s[i]==s[j])
                    {
                    dp[i][j]=true;
                    ans_i=i, ans_j=j;
                    }
                    else dp[i][j]=false;
                }
                else
                {
                if(s[i]==s[j] && dp[i+1][j-1]==true)
                    {
                        dp[i][j]=true;
                           ans_i=i, ans_j=j;
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
            }
        }
        string str="";
        for(int i=ans_i; i<=ans_j; i++)
        {
            str.push_back(s[i]);
        }
        return str;
    }
};