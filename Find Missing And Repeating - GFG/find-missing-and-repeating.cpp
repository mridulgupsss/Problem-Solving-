// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int xorx=0;
        for(int i=1; i<=n; i++){
            xorx^=i;
        }
        for(int i=0; i<n; i++){
            int val=arr[i];
            xorx^=val;
        }
        int rmsbm= xorx & -xorx;
        int x=0, y=0;
        for(int i=1; i<=n; i++){
            if((i & rmsbm)==0){
                x^=i;
            }
            else{
                y^=i;
            }
        }
        for(int i=0; i<n; i++){
            int val=arr[i];
            if((val & rmsbm)==0){
                x^=val;
            }
            else{
                y^=val;
            }
        }
      int rep;
        for(int i=0; i<n; i++){
            int val = arr[i];
            if(val==x) rep=x; 
            if(val==y) rep=y;
        }
         
         int *ans = new int[2];
         ans[0]=rep;
         ans[1]=rep==x?y:x;
         
         return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends