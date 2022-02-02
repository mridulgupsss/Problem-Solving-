class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit=0, minn=arr[0];
        for(int i=1; i<arr.size(); i++)
        {
            minn=min(arr[i], minn);
            profit=max(profit, arr[i]-minn);
        }
        return profit ;
    }
};