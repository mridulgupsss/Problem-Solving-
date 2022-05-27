class Solution {
public:
    int rob(vector<int>& arr) {
       int n =arr.size();
        int take [n];
        int nottake[n];
        take[0]=arr[0];
        nottake[0]=0;
        for(int i=1; i<n; i++){
            take[i]=nottake[i-1]+arr[i];
            nottake[i]= max(nottake[i-1], take[i-1]);
        }
        
        return max(take[n-1], nottake[n-1]);
        
        
    }
};