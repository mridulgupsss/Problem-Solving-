class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int n =arr.size();
        int sum = 0; int len =n+1;
        for(int i=0, j=0; i<n; i++){
            // acquire :
            sum+=arr[i];
           if(sum<target) continue;
            
            
            //release
            while(sum>target){  
                sum-=arr[j];
                j++;
            }
            
 
            if(sum==target) {
                len = min(len, i-j+1);
                sum-=arr[j];
                j++;
            
            }
            else{
                len = min(len, i-j+2);
            }

        
        }
        
        if(len==n+1) return 0;
        return len;
    }
};