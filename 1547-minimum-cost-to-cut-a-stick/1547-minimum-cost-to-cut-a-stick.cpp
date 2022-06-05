class Solution {
public:
    int helper(vector<int> &arr, int i, int j, vector<vector<int>> &memo){
       // basecase: 
        if(i>j) return 0;
        
        
        if(memo[i][j]!=-1) return memo[i][j];
        int mn =INT_MAX;
        for(int idx=i; idx<=j; idx++){
            int ans =  arr[j+1] - arr[i-1] + helper(arr, i, idx-1, memo) + helper(arr, idx+1, j, memo);
            mn= min(mn, ans);
        }
        memo[i][j] = mn;
        return mn;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> arr;
        arr.push_back(0);
        for(auto val: cuts){
            arr.push_back(val);
        }
        arr.push_back(n);
        int m= arr.size();
        vector<vector<int>> memo(m-1, vector<int> (m-1, -1));
        return helper(arr, 1, m-2, memo);
    }
};