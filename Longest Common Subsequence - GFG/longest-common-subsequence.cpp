// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    ///using memoization
    int helper(string &s1, string &s2,int i, int j, int **mem)
    {
        int n=s1.length(), m=s2.length(), c1=s1[i], c2=s2[j];
        //base case:
        if(i==n || j==m) return 0;
        if(mem[i][j]!=-1) return mem[i][j];
        
        //call:
        if(c1==c2){
            mem[i][j]=helper(s1, s2, i+1, j+1, mem) + 1;
            return helper(s1, s2, i+1, j+1, mem) + 1;
        }
        // else
            mem[i][j]=max(helper(s1,s2,i, j+1, mem), helper(s1,s2,i+1,j, mem));
            return max(helper(s1,s2,i, j+1, mem), helper(s1,s2,i+1,j, mem));
        
        
        
    }
    
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int **mem=new int*[x];
        for(int i=0; i<x; i++)
        {
            mem[i]=new int[y];
        }
        
        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                mem[i][j]=-1;
            }
        }
        return helper(s1, s2, 0, 0, mem);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends