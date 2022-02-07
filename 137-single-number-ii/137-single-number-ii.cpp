class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int n = arr.size(); int ans=0;
        for(int i=0; i<=31; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                int val = arr[j];
                if(((val>>i) & 1)!=0){
                    cnt++;
                }
            }
            
            if(cnt%3!=0){
                ans = ans | (1<<i);
            }
        
        }
        
        return ans;
    }
};