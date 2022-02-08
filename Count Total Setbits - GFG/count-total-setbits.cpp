// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fun(int n){
        int x=-1;
        for(int i=1; i<=n; i*=2){
            x++;
        }
        return x;
    }
    int countBits(int n){
        // code here
        if(n==0) return 0;
        int x= fun(n);
        int ans = (1<<(x-1))*x + n-(1<<x)+1 + countBits(n-(1<<x));
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends