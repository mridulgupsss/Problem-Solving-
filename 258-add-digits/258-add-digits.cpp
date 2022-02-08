class Solution {
public:
    int addDigits(int num) {
        while(num/10!=0){
            num = (num%10) + (num/10);
        }
        return num;
    }
};