// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
int fun(vector<int> &v, int c, int target){
    int lo=0, hi=c-1,  potential_ans=c;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(v[mid]<=target) lo=mid+1;
        else{
            potential_ans =mid;
            hi=mid-1;
        }
     }
    return potential_ans;
}
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here   
        int lo=1, hi=2000;
        
        while(lo<=hi){
         int mid=(lo+hi)/2;
         int cnt=0;
         for(int i=0; i<r; i++){
             cnt+=fun(matrix[i], c, mid);
             
         }
         if(cnt<(r*c+1)/2) lo=mid+1;
         else hi=mid-1;
        }
        return lo;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends