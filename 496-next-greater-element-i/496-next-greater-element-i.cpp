class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
        unordered_map<int, int> ans;
        int n = num2.size();
        stack<int> st;
        st.push(num2[0]);
        
        for(int i=1; i<n; i++){
            // pop ans mark ans 
          while(!st.empty() && st.top()<num2[i]){
              ans[st.top()]=num2[i];
              st.pop();
          }  
            
            // push
            st.push(num2[i]);
            
        }
        while(!st.empty()){
            ans[st.top()]=-1;
            st.pop();
        }
        
        vector<int> ret;
        for(auto val: num1){
            ret.push_back(ans[val]);
        }
        return ret;
    }
};