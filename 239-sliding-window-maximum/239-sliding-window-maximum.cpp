class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq; // storijng indices
        int n = arr.size();
        for(int i=0; i<n; i++){
            // popping front if size is overflowing
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            
            // popping while inserting current at correct position in dq
            while(!dq.empty() && arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            if(i>=k-1) ans.push_back(arr[dq.front()]);
            
        }
        
        return ans;
    }
};