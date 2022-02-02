class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n=arr.size();
        int flag=1;
        for(int i=0; i<n; i++){
            if(arr[i]==1) flag=0;
            if(arr[i]<1 || arr[i]>n){
                arr[i]=1;
            }
            
        }
        
        if (flag==1) return 1;
        
        for(int i=0; i<n; i++){
            int ele=abs(arr[i]);
             arr[ele-1]=-1*abs(arr[ele-1]);
        }
        for(int i=0; i<n; i++){
            if(arr[i]>0) return i+1;
        }
        return n+1;
        
        
    }
};