class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end()); int n =beans.size();

        
        long long int pre[n],  suff[n]; long long int s=0;
        for(int i=0; i<n; i++){
            s+=beans[i];
            pre[i]=s;
        }
        s=0;
        for(int i=n-1; i>=0; i--){
            s+=beans[i];
            suff[i]=s;
        }
        long long int ans = s-n*1LL*beans[0];
        for(int i=1; i<n; i++){
            ans=min(ans, pre[i-1]+suff[i]- ((n-i)*1LL*beans[i]));
        }
        
        
        return ans;
    }
};