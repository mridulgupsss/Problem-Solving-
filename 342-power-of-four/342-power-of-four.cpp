class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int fact = 0b01010101010101010101010101010101;
        if(((n&(n-1))==0) && (n&fact)>0) return true;
        return false;
    }
};