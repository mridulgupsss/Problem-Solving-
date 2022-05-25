class Solution {
public:
    int trap(vector<int>& arr) {
        int n= arr.size();
        int i=0, j=n-1;
        int ans=0;
        int left_max=arr[0], right_max=arr[n-1];
        while(i<j){
            
           if(arr[i]>left_max){
                left_max=arr[i];
            }
            if(arr[j]>right_max){
                right_max=arr[j];
            }     
          
            if(left_max<right_max){
                ans+=left_max-arr[i]; i++;
            }
            else {
                ans+=right_max-arr[j]; j--;
            }
           
            
            
            

        }
        return ans;
    }
};