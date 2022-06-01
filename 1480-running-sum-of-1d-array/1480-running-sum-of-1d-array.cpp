class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        for(auto &val : nums){
            sum+=val;
            val=sum;
        }
        
        return nums;
    }
};