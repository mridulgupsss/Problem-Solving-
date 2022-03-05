class Solution {
public:
    vector<array<int,2>> num;
    int dp[10001]={};
    int sz;
    int fun(int l)
    {
        if(l==sz)
            return 0;
        if(dp[l]) return dp[l];
        int val=num[l][0]*num[l][1];
        if(l+1<sz and num[l][0]==num[l+1][0]-1)
            return dp[l]=max(val+fun(l+2),fun(l+1));
        if(l+1<sz and num[l][0]!=num[l+1][0]-1)
            return dp[l]=val+fun(l+1);
        else
            return dp[l]=val;
        
    }
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto n:nums)
            mp[n]++;
        for(auto it:mp)
            num.push_back({it.first,it.second});
        sz=num.size();
        return fun(0);
        
    }
};