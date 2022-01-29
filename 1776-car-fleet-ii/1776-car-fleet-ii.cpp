class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        stack<int> st;
        int n = cars.size();
        vector<double> ans(n);
        ans[n-1]=-1;
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st.empty()){
            
                if(cars[i][1]<=cars[st.top()][1]) st.pop();
                else
                {
                    double time = (cars[st.top()][0] - cars[i][0])*1.0 / (cars[i][1] - cars[st.top()][1]);
                    if(time > ans[st.top()] && ans[st.top()]!=-1){
                        st.pop(); 
                    }
                    else{
                        ans[i]=time;
                        st.push(i);
                        break;
                    }
                }
            }
            
            if(st.empty()){
                 ans[i]=-1;
                st.push(i);
            }
        }
        
        return ans;
    }
};