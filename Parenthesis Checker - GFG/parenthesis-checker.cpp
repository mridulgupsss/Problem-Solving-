// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        unordered_map<char, int> m;
        m['(']=-1; m['{']=-2; m['[']=-3;
        m[')']=1; m['}']=2; m[']']=3;
        
        stack<int> st;
        
        for(auto ch: s){
            if(m[ch]<0){
                st.push(ch);        
            }
            else{
                if(st.empty()) return false;
                if(m[st.top()]+m[ch]!=0) return false;
                st.pop();
            }
        }
        
        if(st.empty()) return true;
        return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends