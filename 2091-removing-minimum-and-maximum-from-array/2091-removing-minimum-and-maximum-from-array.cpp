class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i, j;int mx=INT_MIN; int mn = INT_MAX;
        int n =nums.size();
        for(int ii=0; ii<n; ii++){
            if(nums[ii]>mx){
                j=ii;
                mx=nums[ii];
            }    
            if(nums[ii]<mn){
                mn=nums[ii];
                i=ii;
            }
        }
    int iii=min(i, j);
        int jjj =max(i, j);
        
        int ans = min({jjj+1, n-iii, iii+1+ n-jjj });
        return ans;
    }
};