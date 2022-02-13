class Solution {
public:  // Tech Dose approach
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int ans=0;
        int st=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<end) {
                // 2cases
                if(intervals[i][1]<=end){
                    // remove previos onoe 
                    ans++;
                    st=intervals[i][0];
                    end=intervals[i][1];
                }
                else{
                    // remove this interval
                    ans++;
                    
                }
                
                
            }
            else{
                st=intervals[i][0];
                end=intervals[i][1];
            }
        }
        return ans;
            
            
    }
};