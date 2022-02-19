class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
       int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(0);
        for(int i=1; i<n; i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
            
        }
        
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            
           
        }
        
        while(!st.empty()){
            ans[st.top()]=-1;
            st.pop();
        }
        
        return ans;
    }
};