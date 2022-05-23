class Solution {
public:
    
    // https://www.youtube.com/watch?v=qq64FrA2UXQ
    
    
    int getSum(int a, int b) {
        while(b!=0){
            unsigned carry_mask = a&b;
            a = a^b;
            
            b = carry_mask<<1;
                
            
        }
        
        return a ;
    }
};