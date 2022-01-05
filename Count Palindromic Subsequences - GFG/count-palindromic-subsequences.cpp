// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string A)
    {
       //DP
            int n=A.length();
        long long int dp[n][n], mod=1000000007;
        for(int gap=0; gap<n; gap++)
        {
            for(int i=0,j=gap; i<n-gap; j++, i++)
            {
                if(gap==0) dp[i][j]=1;
                else if (gap==1){
                    if(A[i]==A[j]) dp[i][j]=3;
                    else dp[i][j]=2;
                }
                else
                {
                       if(A[i]==A[j]) dp[i][j]=((((dp[i+1][j]%mod) + (dp[i][j-1]%mod))%mod)+1)%mod;
                    else dp[i][j]= ((((((dp[i+1][j]%mod)+ (dp[i][j-1])%mod))%mod) - (dp[i+1][j-1]%mod))%mod + mod)%mod;
                }
            }
        }
        return dp[0][n-1]%mod;
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends