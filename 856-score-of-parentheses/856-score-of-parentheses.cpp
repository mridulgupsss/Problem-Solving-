class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(auto ch : s){
            if(ch=='('){
                st.push(0);
            }
            else{
                
                if(st.top()==0) {
                    st.pop();
                    st.push(1);
                }
                else{
                    int add=0;
                    while(st.top()!=0){
                           add+=st.top();
                           st.pop();
                        }
                        st.pop();
                    st.push(2*add);
                }
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};