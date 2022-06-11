class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int n = arr.size();
        vector<int> suff(n , 0), pref(n, 0);
        unordered_map<int, int> mp;
        int ans =INT_MAX;
        for(int i=0; i<n; i++){
            if(i==0) {
                pref[i]=arr[i];
                suff[n-1]=arr[n-1];
            }
            else{
                pref[i] = pref[i-1]+arr[i];
                suff[n-i-1] = suff[n-i]+arr[n-i-1];
                

            }
            
                if(pref[i]==x){
                    ans=min(ans, i+1);
                }
                
                if(suff[n-i-1]==x){
                    ans=min(ans, i+1);
                }
                
                if(mp.find(suff[n-i-1])==mp.end()) 
                    mp[suff[n-i-1]]=i+1;
            
        }
        
        for(int i=0; i<n; i++){
            int target = x - pref[i];
            if(mp.find(target)!=mp.end() && mp[target]<=n-i-1){
                ans = min(ans, i + 1 + mp[target]);
            }
        }
        
        return ans==INT_MAX?-1:ans;
        
        
        
        
        
        
    }
};