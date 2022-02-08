class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int flag=0;
        int j=0;
        int ans =0;
        for (int i=31; i>=0; i--){
            if(((1<<i)& n)==0 && flag==1){
                // bit is off
                j++;
            }
            else if(((1<<i)& n)!=0){
                flag=1;
                
                ans=ans | (1<<j);
                j++;
            }
        }
        if(j==0) return ans;
        return ans<<(32-j);
    }
};