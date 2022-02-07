class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        for(int i=0; i<n-1; i++){
            int xorx=arr[i];
            for(int k=i+1; k<n; k++){
                xorx^=arr[k];
                
                if(xorx==0){
                    cnt+=k-i;
                }
            }
        }
        return cnt;
    }
};