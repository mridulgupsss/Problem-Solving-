class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        int n=speed.size();
        for(int i=0; i<n; i++){
            v.push_back({position[i], speed[i]});
            
        }
        sort(v.begin(), v.end());
 
        
        int ans=1; 
        float time = ((target-v[n-1].first)*1.0 )/ v[n-1].second;
        for(int i=n-2; i>=0; i--){
            float curr_time = ((target-v[i].first)*1.0 )/ v[i].second;

            if(curr_time > time){
                
                ans++;
                time = curr_time;
            }
            
        }
        
        return ans;
    }
};