class Solution {
public:

    int rob(vector<int>& nums) {

      
        
        int prev1= nums[0];
        int prev2=0;
       
        for(int i=0; i<nums.size(); i++){
             int taken = nums[i];
            if(i-2>=0)taken+=prev2;
             int nottaken =0;
            if(i>=1) nottaken=prev1;
            int curr=max(taken, nottaken);
            
            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;
        
     
    }
};