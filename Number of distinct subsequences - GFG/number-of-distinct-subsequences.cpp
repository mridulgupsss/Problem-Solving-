// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int mod=1000000007;
	       int n=s.length();
	    int dp[n+1]; dp[0]=1;
	 
	    unordered_map<char, int> lo;
	    for(int i=1; i<=n; i++)
	    {
	        char ch=s[i-1];
	        if(lo.find(ch)==lo.end())
	        {
	            lo[ch]=i;
	            dp[i]=(2*dp[i-1])%mod;
	        }
	        else{
	            dp[i]=(((2*dp[i-1])%mod - dp[lo[ch]-1])%mod +mod)%mod;
	             lo[ch]=i;
	        }
	    }
	    return dp[n];
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends