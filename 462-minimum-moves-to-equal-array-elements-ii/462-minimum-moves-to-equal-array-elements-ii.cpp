class Solution {
public:
    int minMoves2(vector<int>& nums) {
       int mn = INT_MAX, mx=INT_MIN;int n =nums.size();
sort(nums.begin(), nums.end());
        int s=0, ss=0;
        int x=nums[n/2];
        
        for(auto b:nums){
            s+=abs(x-b);
        }
        
        if(n%2==0){
            int xx=nums[n/2-1];
            for(auto bb: nums){
                ss+=abs(xx-bb);
            }
        }
        
        if(ss==0) return s;
    
        return min(s, ss);
    }
};