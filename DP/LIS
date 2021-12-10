class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=1;
        int ans=dp[0];
        for(int i=1; i<n; i++)
        {
            int maxx=0; int val=nums[i];
            for(int j=0; j<i; j++)
            {
                if(nums[j]<val){
                    maxx=max(maxx, dp[j]);
                    
                }
                
            }
            dp[i]=maxx+1;
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};