class Solution {
public:

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        int n =questions.size();
        dp[n-1]=questions[n-1][0];
        for(int i=n-2; i>=0; i--){
        long long pick = questions[i][0] ;
            if(i+questions[i][1]+1<n) pick+= dp[i+questions[i][1]+1];
        long long notpick = 0;
            if(i<n-1) notpick=dp[i+1];
         dp[i] = max(pick, notpick);
        }
        
        return dp[0];
    }
};