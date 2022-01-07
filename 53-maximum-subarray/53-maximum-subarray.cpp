class Solution {
public:// kadane algorithm:
    int maxSubArray(vector<int>& nums) {
        int curr=0, best=nums[0];
        for(auto val:nums){
            if(curr+val>val) curr+=val;
            else curr=val;
            
            if(curr>best) best=curr;
            }
        return best;
        }
    
};