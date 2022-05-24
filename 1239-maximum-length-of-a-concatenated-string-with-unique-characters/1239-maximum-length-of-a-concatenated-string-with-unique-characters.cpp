class Solution {
public:
    // https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/discuss/1089007/Pure-bit-manipulation-beats-93
    
    
    int str2mask(string &s){
        int ans =0;
        for(auto ch: s){
            int msk = (1<<(ch-'a'));
            if((msk&ans)!=0){return -1;}
            ans=ans|msk;
        }
        return ans;
    }
    int helper(vector<string>& arr, int idx, int full_mask){
         // base case
        if(idx==arr.size()){
            return __builtin_popcount(full_mask);
        }
        
        int without = helper(arr, idx+1, full_mask);
        int mask = str2mask(arr[idx]);
        int with=0;
        
        if( (mask==-1) || (mask&full_mask)!=0) with=0;
         else with = helper(arr, idx+1, mask|full_mask);
        
        
        return max(with, without);

    }
    int maxLength(vector<string>& arr) {
       
         return helper(arr, 0, 0);
    }
};