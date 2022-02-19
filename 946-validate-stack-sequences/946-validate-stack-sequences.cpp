class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0; int j=0;
        int n =pushed.size();
        while(i<n){
          st.push(pushed[i]);
            while(!st.empty() && st.top()==popped[j]){
                 st.pop(); j++;
            }
            
            i++;
        }
        
     if(st.empty()) return true ;
        return false;
        
    }
};