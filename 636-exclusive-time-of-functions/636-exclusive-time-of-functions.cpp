class Solution {
public:
    class log{
        public:
        int id;
        int time;
        int child_time;

    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<log> st;
        for(auto itr : logs){
            stringstream ss(itr);
            string temp1, status, temp3;
            getline(ss, temp1, ':');
            getline(ss, status, ':');
            getline(ss, temp3, ':');
            
            
            log curr;
            curr.id = stoi(temp1);
            curr.time = stoi(temp3);
            curr.child_time=0;
            
            
            if(status=="start"){
                st.push(curr);
            }
            else{
                int duration = curr.time- st.top().time+1;
                int child = duration;
                duration-=st.top().child_time;
                ans[curr.id]+=duration; st.pop();
                
                if(!st.empty()) st.top().child_time+=child;
                
                
            }
        }
        
        return ans;
    }
};