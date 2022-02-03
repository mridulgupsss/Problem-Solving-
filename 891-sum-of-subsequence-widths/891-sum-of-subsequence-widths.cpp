class Solution {
public:
    int sumSubseqWidths(vector<int>& arr) {
        int mod=1e9 +7;
        int ans=0;
        int n=arr.size();
        vector<int> pow(n);
        pow[0]=1;
        for(int i=1; i<n; i++){ // pow[i] = 2 power i
            pow[i]=(pow[i-1]*2)%mod;
        }
        sort(arr.begin(), arr.end()); // answer would still be same doesnt matter

        for(int i=0; i<arr.size(); i++){
            ans = (ans + (arr[i]*1LL*(pow[i] - pow[n-i-1])%mod)%mod)%mod;
        }
        
        return ans;
        
        
    }
};