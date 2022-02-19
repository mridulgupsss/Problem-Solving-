class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        stack<int> st;
        for(auto ch: s){
            if(ch=='(') st.push(1);
            else{
                if(st.empty()) ans+=1;
                else st.pop();
            }
        }
        
        ans+=st.size();
        return ans;
    }
};