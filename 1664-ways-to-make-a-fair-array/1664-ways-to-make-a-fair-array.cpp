class Solution {
public:
    int waysToMakeFair(vector<int>& arr) {
        int n= arr.size();
        int even=0, odd=0;
        for(int i=0; i<n; i++){
            if(i%2==0) even+=arr[i];
            else odd += arr[i];
        }
       
        int prev_even=0, prev_odd=0;
        int ans=0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                int next_odd= even - prev_even - arr[i];
                int next_even = odd - prev_odd;
                
                if((prev_odd + next_odd)== (prev_even+next_even)) ans++;
                
                prev_even+=arr[i];
            }
            else{
                int next_odd= even - prev_even;
                int next_even = odd - prev_odd - arr[i];
                
                if(prev_odd + next_odd== prev_even+next_even) ans++;
                
                prev_odd+=arr[i];                
            }
        }
        return ans;
        
    }
};