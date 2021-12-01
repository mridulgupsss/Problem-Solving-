class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0);
        dp[n-1]=0;
        for(int i=n-2; i>=0; i--)
        {
            int minn=n;
            int c=1;
            for(int j=i+1; j<n && c<=nums[i]; j++, c++)
            {
                if(dp[j]>=0)
                minn=min(minn, 1+dp[j]);
            }
            
            if(nums[i]==0) dp[i]=-1;
            else
            {
                dp[i]=minn;                
            }
        }
        return dp[0];
    }
};