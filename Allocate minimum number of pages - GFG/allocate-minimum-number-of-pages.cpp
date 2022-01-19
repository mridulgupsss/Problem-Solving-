// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int allocatedStudents(int a[], int n, int books){
        int allocated=1, sum=0;
        for(int i=0; i<n; i++){
            if(sum+a[i]<=books)sum+=a[i];
            else{
                allocated++;
                sum=a[i];
            }
        }
        
        return allocated;
    }
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        int maxx=INT_MIN;
        int sum=0;
        for(int i=0; i<n; i++){
           maxx=max(maxx, a[i]);
           sum+=a[i];
        }
        int lo=maxx, hi=sum;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(allocatedStudents(a, n, mid)<=m){
                ans=mid; //p[otential ans;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends