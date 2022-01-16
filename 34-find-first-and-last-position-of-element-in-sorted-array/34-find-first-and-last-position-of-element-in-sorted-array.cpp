class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0, hi=n-1;
        int en=-1, st=-1; 
        while(lo<=hi){
            int mid =(lo+hi)/2;
            if(nums[mid]>target) hi=mid-1;
            else if(nums[mid]<target) lo=mid+1;
            else {
                en=mid; // potential ans
                lo=mid+1;
            }
        }
        
       
        
        lo=0, hi=n-1;
        while(lo<=hi){
            int mid =(lo+hi)/2;
            if(nums[mid]>target) hi=mid-1;
            else if(nums[mid]<target) lo=mid+1;
            else {
                st=mid; // potential ans
                hi=mid-1;
            }
        }
        
     vector<int> v;
        v.push_back(st);
        v.push_back(en);
        
        return v;
    }
};