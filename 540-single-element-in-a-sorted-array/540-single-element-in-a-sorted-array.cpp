class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=0, hi=n-1, ans;
        
        // edge cases:
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0]; // cases vwhen 1st element is umique  
        if(nums[hi]!=nums[hi-1]) return nums[hi];  // casese whem last element is unique
        
        
        // actual code 
        lo=1, hi=n-2;
            while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid]) {
            ans=mid; break; }
            else if(mid%2==0){
                if(nums[mid-1]==nums[mid]){
                    hi=mid-2;
                }
                else{
                    lo=mid+2;
                }
            }
            else
            {
                if(nums[mid+1]==nums[mid]){
                   hi=mid-1; 
                }
                else{
                    lo=mid+1;
                } 
            }
        }
        return nums[ans];
    }
};