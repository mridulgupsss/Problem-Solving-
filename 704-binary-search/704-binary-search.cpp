class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1, ans=-1;
        
        while(hi>=lo){
            int mid=(lo+hi)/2;
            
            if (nums[mid]==target){
                ans=mid; 
                break; // dont forget very imp
            }
            else if(nums[mid]>target)
                hi=mid-1;
            else 
                lo=mid+1;
        }
        
        return ans;
    }
};