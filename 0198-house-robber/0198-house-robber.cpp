class Solution {
public:
    int recursive(int idx, vector<int> &nums, vector<int> &mem){
       
        if(idx==0) return nums[idx];
        if(idx<0) return 0;
        
        if(mem[idx]!=-1) return mem[idx];
        int taken = nums[idx]+recursive(idx-2, nums, mem);
        int nottaken = recursive(idx-1, nums, mem);
        
        return mem[idx]=max(taken, nottaken);
    }
    int rob(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        return recursive(nums.size()-1, nums, mem);
    }
};