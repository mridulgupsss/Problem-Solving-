class Solution {
public:
    int nthUglyNumber(int n) {
         vector<long long>dp(n+1);
        for(int i=1; i<=n; i++){
            if(i==1){
                dp[i]=1;
            }
            else{
            long long ans=INT_MAX;
            for(int j=i-1; j>=1; j--){

                if(dp[j]*2>dp[i-1]){
                    ans=min(ans, dp[j]*2);
                }
                                if(dp[j]*3>dp[i-1]){
                    ans=min(ans, dp[j]*3);
                }
                                if(dp[j]*5>dp[i-1]){
                    ans=min(ans, dp[j]*5);
                }
            }
            dp[i]=ans;
            }
            

        }
        
        return dp[n];
    
}
};