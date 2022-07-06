class Solution {
public:
    int helper(int n, vector<int> &mem){
           if(n==0 || n==1 || n==2){
           if(n==0 || n==1) {;return n;}
           else return 1;
              } 
        if(mem[n]!=-1) return mem[n];
        
        return mem[n] = helper(n-1, mem)+helper(n-2,mem)+helper(n-3, mem);
    }
    int tribonacci(int n) {
        vector<int> mem(n+1, -1);
        return helper(n, mem);
    }
};