class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        unordered_map<int, int> mp; int ans=0;
        for(auto val: arr){
            mp[val]++;
        }
        
        for(auto it: mp){
            int val = it.first;
            int target =val-k; // consider val>other value
            if((k>0 && mp.find(target)!=mp.end()) || (k==0 && mp[val]>1)){
                ans++;
            }
        }
        return ans;
    }
};