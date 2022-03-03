class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int ans=0,consecutive=0;
        for(int i=2;i<nums.size();i++){
            
            if(nums[i-1] - nums[i-2] == nums[i] - nums[i - 1]){
                   consecutive+=1;
                   ans+=consecutive;
            }
            else{
               
                consecutive=0;
            }
        }
        
        return ans;
    }
};