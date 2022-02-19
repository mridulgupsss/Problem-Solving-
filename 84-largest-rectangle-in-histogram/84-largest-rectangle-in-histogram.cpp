class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        // next smaller ele to left and right 
        stack<int> st;
        int n = arr.size();
    int ans =0;
        st.push(0);
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || arr[i]<arr[st.top()])){
                int idx=st.top();
                st.pop();
                if(st.empty()){
                    int potential =(arr[idx]*1LL*(i));
                    ans=max(ans, potential);
                }
                else{
                    int potential = arr[idx]*1LL*(i-st.top()-1);
                    ans = max(ans, potential);
                }
            
            }
            
            st.push(i);
        }
    
        return ans;
    }
};