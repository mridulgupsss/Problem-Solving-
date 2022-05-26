class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0){
            int mask = n& (-n);
            count++;
            n-=mask;
        }
        return count;
        
    }
};