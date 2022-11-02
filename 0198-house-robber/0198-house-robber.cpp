class Solution {
public:

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
      
        
        dp[0]= nums[0];
      //  if(idx<0) return 0;
        
        //if(mem[idx]!=-1) return mem[idx];
       
        for(int i=0; i<nums.size(); i++){
             int taken = nums[i];
            if(i-2>=0)taken+=dp[i-2];
             int nottaken =0;
            if(i>=1) nottaken=dp[i-1];
            dp[i]=max(taken, nottaken);
        }
        
        return dp[nums.size()-1];
        
     
    }
};