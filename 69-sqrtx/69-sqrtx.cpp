class Solution {
public:
    int mySqrt(int x) {
        int lo=0, hi=x, ans;
        
        while(hi>=lo){
            int mid=(lo+hi)/2;
            
            if (mid*1LL*mid==x){
                ans=mid; 
                break; // dont forget very imp
            }
            else if(mid*1LL*mid>x)
                hi=mid-1;
            else {
                ans=mid;  // pootential ans (very imp line)
                lo=mid+1;
                
            }
                
        }
        
        return ans;
    }
};