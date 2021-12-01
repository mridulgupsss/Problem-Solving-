class Solution {
public:
    int helper(int n, vector<int>& arr)
    {
        if(n==0 || n==1) return n;
        if(arr[n]!=0) return arr[n];
        int fibn=helper(n-1, arr)+helper(n-2, arr);
        arr[n]=fibn;
        return fibn;;
    }
    int fib(int n) {
        vector<int> mem(n+1, 0);
        return helper(n, mem);
    }
};