class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0; 
        int j=nums.size(); // because search space also include nums.size() this time 
        int ans;
        while(i<=j){
            int mid =(i+j)/2;
            if(mid==nums.size())return mid ;
            if(nums[mid]<target){
                i=mid+1;
            }
            else if(nums[mid]>target){
                ans=mid;  // ans = potetIAL ANS 
                j=mid-1;
            }
            else{
                return mid;
            }
        }
        
        return ans;
        
    }
};