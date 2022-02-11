class Solution {
public:
    
//  https://leetcode.com/problems/construct-target-array-with-multiple-sums/discuss/573511/Explain-how-the-works
    
    
    bool isPossible(vector<int>& arr) {
        long sum=0;
        priority_queue<int> pq;
        for(auto ele: arr){
            pq.push(ele);
             sum+=ele;
        }
        while(pq.top()!=1){
            int mxx= pq.top();
            pq.pop();
            long remaining_sum =sum - mxx;

            if(remaining_sum<=0 || remaining_sum>=mxx) return false;
            int val=mxx % remaining_sum;
            pq.push(val==0 ? remaining_sum : val);           
            sum=val+remaining_sum;
            
        }
        return true;
    }
};