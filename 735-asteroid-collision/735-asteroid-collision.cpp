class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0; i<asteroids.size(); i++){
            int push=1;
            while(!st.empty() && st.top()>0 && asteroids[i]<0 && abs(asteroids[i])>=st.top()){
                if(abs(asteroids[i])==st.top()){
                    push=0;
                    st.pop();
                    break;
                }
                st.pop();
            }
            if(!st.empty() && asteroids[i]<0 &&st.top()>abs(asteroids[i])){
                push=0;
            }
            
            if(push==1) st.push(asteroids[i]);
        }
        
        vector<int> ans(st.size());
        for(int i=st.size()-1; i>=0; i--){
            ans[i]=st.top();
            st.pop();
        }
        
        return ans;
    }
};