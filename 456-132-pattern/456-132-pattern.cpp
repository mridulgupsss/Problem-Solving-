class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        int n = arr.size();
        int min_till_now[n];
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            mn =min(arr[i], mn);
            min_till_now[i]=mn;
        }
        
        stack<int> st;
        st.push(arr[n-1]);
        for(int j=n-2; j>=1; j--){
            int i_val = min_till_now[j-1];
            int j_val = arr[j];
            while(!st.empty() && st.top()<=i_val) st.pop();
            if(!st.empty() && st.top()<j_val){
                return true;
            }
            st.push(j_val);
        }
        
        return false;
    }
};