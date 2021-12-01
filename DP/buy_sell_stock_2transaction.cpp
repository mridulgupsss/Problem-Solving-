class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        int n = arr.size();
        int left[n];
        left[0] = 0;
        int right[n];
        right[n - 1] = 0;
        int min_till_i = arr[0], lprofit = 0;
        for (int i = 1; i < n; i++)
        {
            int currprofit = arr[i] - min_till_i;
            if (currprofit > lprofit)
                lprofit = currprofit;
            if (arr[i] < min_till_i)
                min_till_i = arr[i];
            left[i] = lprofit;
        }

        int max_till_last = arr[n - 1], rprofit = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int currprofit = max_till_last - arr[i];
            if (currprofit > rprofit)
                rprofit = currprofit;
            if (max_till_last < arr[i])
                max_till_last = arr[i];
            right[i] = rprofit;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, right[i] + left[i]);
        }
        return ans;
    }
};