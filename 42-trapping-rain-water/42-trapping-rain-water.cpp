class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size()), right(height.size());
         int n =height.size();
        int mn = height[0];
        int idx=0;
                left[0]=0;
        right[n-1]=n-1;
       
        for(int i=1; i<n; i++){
        if(height[i]>=mn){
            left[i]=i;
            idx=i;
            mn=height[i];
        }
            else{
                left[i]=idx;
            }
  
        }
  
        idx=n-1;
        mn = height[idx];
        for(int i=n-2; i>=0; i--){
        if(height[i]>=mn){
            right[i]=i;
            idx=i;
            mn=height[i];
        }
            else{
               right[i]=idx;
            }            
            
  
        }

        int ans=0;
        for(int i=1;i<n-1; i++){
            int r = height[right[i+1]];
            int l  =height[left[i-1]];
            
            int less = min(l,r);
            if(less>height[i]){
                ans+=(less-height[i]);
                
                    
            }
        }
        
        
        return ans;
        
        
        
    }
};