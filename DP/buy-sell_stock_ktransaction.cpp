class Solution
{
public:
    int maxProfit(int k, vector<int> &arr)
    {
        int dp[k + 1][arr.size() + 1];
        for (int i = 0; i < k + 1; i++)
        {
            for (int j = 0; j < arr.size() + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;

                else if (j == 0)
                dp[i][j]=0;

                else
                {
                    int maxx=0;
                    for(int idx=j-1; idx>=1; idx--)
                    {
                        maxx=max(maxx, dp[i-1][idx]+ arr[j-1]-arr[idx-1]);
                    }
                    dp[i][j]=max(maxx, dp[i][j-1] );
                }
            }
        }
        return dp[k][arr.size()];
    }
};