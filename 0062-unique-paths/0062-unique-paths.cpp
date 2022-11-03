class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<int> dp(m,0);
        int curr; int prev;
           for(int i=n-1; i>=0; i--){
               prev=0; 
               for(int j=m-1; j>=0; j--){
                   if(i==n-1 && j==m-1){
                       curr= 1;
                       
                   }
                   else if(j==m-1){
                       curr=dp[j];
                       
                   }
                   else if(i==n-1){
                       curr=prev;
                   }
                   else{
                       curr=prev + dp[j];
                   }
                   
                   dp[j]=curr;
                   prev=curr;
               }
           }
           
           return prev;
       } 
    
};