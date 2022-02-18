class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
        unordered_map<int, int> ans;
        int n = num2.size();
        stack<int> st;
        st.push(num2[n-1]);
        ans[num2[n-1]]=-1;
        for(int i=n-2; i>=0; i--){
            // pop
          while(!st.empty() && st.top()<num2[i]){
              st.pop();
          }  
            
            // marking ans 
            if(st.empty()){
                ans[num2[i]]=-1;
            }
            else{
                ans[num2[i]]=st.top();
            }
            
            // pushing
            st.push(num2[i]);
        }
        
        vector<int> ret;
        for(auto val: num1){
            ret.push_back(ans[val]);
        }
        return ret;
    }
};