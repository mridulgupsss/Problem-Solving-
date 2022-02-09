class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a!=0 || b!=0 || c!=0){
            int bit1, bit2, bit3;
            if((a&1)==0){
                bit1=0;
            }
            else{
                bit1=1;
            }
            
            if((b&1)==0){
                bit2=0;
            }
            else{
                bit2=1;
            }
            
            
            if((c&1)==0){
                bit3=0;
            }
            else{
                bit3=1;
            }
            
            if(bit3==1 && bit1==0 && bit2==0){
                ans++;
            }
            else if(bit3==0 ){
                if(bit1==1 && bit2==1) ans+=2;
                else if(bit1==1 || bit2==1) ans++;
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        
        return ans;
    }
};