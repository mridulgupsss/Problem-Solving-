class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double ans;
        for(int i=0; i<k-1; i++){
            sum+=nums[i];
            
        }
        
        for(int i=k-1, j=0; i<nums.size(); i++, j++){
            sum+=nums[i];
            if(i==k-1){ans=sum;}
            else{
                if(sum>ans) ans=sum;
            }
            sum-=nums[j];
        }
        
        return ans/k;
    }
};