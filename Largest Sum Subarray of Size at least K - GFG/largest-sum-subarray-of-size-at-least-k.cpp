// { Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

// pepcoding
long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long int a2[n], curr=a[0];
    a2[0]=curr;
    for(long long int i=1; i<n; i++){
        if(curr>0) curr+=a[i];
        else curr=a[i];
        
        a2[i]=curr;
    }
    long long int sum=0;
    for(long long int i=0; i<k; i++){
        sum+=a[i];
    }
    long long int ans=sum;

    
    for(long long int i=k; i<n; i++){
        sum=sum-a[i-k]+a[i] ; 
        ans=max({ans, sum+a2[i-k], sum});
    }
    return ans;
}
