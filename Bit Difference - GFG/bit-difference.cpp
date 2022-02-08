// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int N, long long int A[])
    {
        int mod= 1000000007;
        // code here
        long long int ans=0;
        for(int i=0; i<64; i++){
            long long int one=0, zero=0;
            for(int j=0; j<N; j++){
                long long int val=A[j];
                if(((val>>i)&1LL)==0) zero++;
                else one++;
            }
           
            ans=(ans + ((((zero*one)%mod)*2)%mod)%mod)%mod;
        }
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
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends