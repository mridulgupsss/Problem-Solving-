class Solution {
public: 
    //  nice article: with 2 approaches ...2nd one same with better code 
    
 /* link:   https://leetcode.com/problems/car-pooling/discuss/1670052/C%2B%2B-or-2-Approaches-or-priority-queue-or-with-intuition-or-Easy-to-understand-explanation-or-STL */
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       int arr[1001]={0};
        for(auto it : trips){
            arr[it[1]]+=it[0];  // be carefull 
            arr[it[2]]+=-it[0];
        }
        int sum=0;
        for(auto val: arr){
            sum+=val;
            if(sum>capacity)return false;
        }
        return true;
        
    }
};