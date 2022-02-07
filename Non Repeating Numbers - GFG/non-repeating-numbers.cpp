// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> arr) 
    {
          int xorx=0;
          for(auto val: arr){
              xorx^=val;
          }
          int rmsbm = xorx & -xorx;
          vector<int> ans(2, 0);
          for(auto val: arr){
              if(val & rmsbm){
                  ans[0]^=val;
              }
              else{
                  ans[1]^=val;
              }
          }
          
          if(ans[0]>ans[1]){
              swap(ans[0], ans[1]);
          }
          return ans;
        
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends