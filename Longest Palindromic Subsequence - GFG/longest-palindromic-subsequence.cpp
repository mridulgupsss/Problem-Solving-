// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //DP
        
        int n=A.length();
        int dp[n][n];
        for(int gap=0; gap<n; gap++)
        {
            for(int i=0,j=gap; i<n-gap; j++, i++)
            {
                if(gap==0) dp[i][j]=1;
                else if (gap==1){
                    if(A[i]==A[j]) dp[i][j]=2;
                    else dp[i][j]=1;
                }
                else
                {
                       if(A[i]==A[j]) dp[i][j]=dp[i+1][j-1]+2;
                    else dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends