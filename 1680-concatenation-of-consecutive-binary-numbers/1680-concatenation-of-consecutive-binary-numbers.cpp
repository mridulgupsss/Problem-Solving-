class Solution {
public:
    int concatenatedBinary(int n) {
        long long mod = 1e9 +7;
        long long len =0;
        long long ans =0; // long long very imp
        for(int i=1; i<=n; i++){
            if((i & (i-1))==0) len++;
           ans = (ans<< len) ; 
            ans=ans|i;
            ans =ans% mod;
        }
        
        return  ans% mod;
        
        
    }
};