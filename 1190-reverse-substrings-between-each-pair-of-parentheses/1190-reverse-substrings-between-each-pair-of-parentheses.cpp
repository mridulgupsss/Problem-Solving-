class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch!=')'){
                st.push(ch);
            }
            else{
                queue<char> q;
                while(st.top()!='('){
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!q.empty()){
                    st.push(q.front());
                    q.pop();
                }
            
            }
        }
        
        stack<char> st2;
                while(!st.empty()){
                    st2.push(st.top());
                    st.pop();
                }
        
        string ans="";
                while(!st2.empty()){
                    ans+=st2.top();
                    st2.pop();
                }
        return ans;
    }
};