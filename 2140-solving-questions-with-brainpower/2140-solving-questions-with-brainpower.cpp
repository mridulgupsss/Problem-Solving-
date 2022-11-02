class Solution {
public:
    long long recursive(vector<vector<int>>& questions, int idx, vector<long long> &dp ){
        
        if(idx==questions.size()-1) return questions[idx][0];
        if(idx>questions.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        long long pick = questions[idx][0] + recursive(questions, idx+questions[idx][1]+1, dp);
        long long notpick = recursive(questions, idx+1, dp);
        return dp[idx] = max(pick, notpick);
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()-1, -1);
        return recursive(questions, 0, dp);
    }
};