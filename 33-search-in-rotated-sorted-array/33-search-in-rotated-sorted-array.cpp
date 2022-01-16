class Solution {
public:
    
    int binSearch(vector<int> v, int i, int j, int x){
        int lo=i, hi=j;
        while(lo<=hi){
            int m=(lo+hi)/2;
            if(v[m]==x)return m;
            else if(v[m]>x) hi=m-1;
            else lo=m+1;

        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int ans=-1;
        int n=nums.size();
        int lo=0, hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]==target) {
                ans=mid;
                break;
            }
            //left portion sorted 
            else if(nums[mid]>=nums[lo]){  // imp to write >= cant just write >
                if(target>=nums[lo] && target<=nums[mid])
                    hi=mid-1;
                else{
                    lo=mid+1;
                }
            }
            //right portion sorted 
            else{
                if(target>=nums[mid] && target<=nums[hi])
                    lo=mid+1;
                else{
                    hi=mid-1;
                }
            }
        }
        return ans;

    }
};