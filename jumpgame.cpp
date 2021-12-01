class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;

        for (int i = n - 2; i >= 0; i--)
        {

            int c = 1;
            for (int j = i + 1; j < n && c <= nums[i]; j++, c++)
            {
                if (dp[j] == true)
                {
                    dp[i] = true;
                    break;
                }
            }
            if (nums[i] = 0)
                dp[i] = false;
        }
        return dp[0];
    }
};