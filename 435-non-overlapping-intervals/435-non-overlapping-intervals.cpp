class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)->bool{
            return a[1]<b[1];
            
        });
        
        int ans=0;
        int st=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<end) {
                ans++;
            }
            else{
                st=intervals[i][0];
                end=intervals[i][1];
            }
        }
        return ans;
            
            
    }
};