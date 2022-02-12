class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
       if(intervals.size()==0)  return ans;
        sort(intervals.begin(),intervals.end());
        pair<int,int> curr(intervals[0][0], intervals[0][1]);
         
        for(auto it : intervals){
            if(it[0]<=curr.second && it[1]>curr.second){
                curr.second=it[1];
            }
            else if(it[0]<=curr.second){
 // nothing to do skip this interval as it is complete;y overlapped
            }
            else{
                vector<int> interval(2);
                interval[0]=curr.first;
                interval[1]=curr.second;
                ans.push_back(interval);
                
                curr.first=it[0];
                curr.second=it[1];
            }
        }
        
                vector<int> interval(2);
                interval[0]=curr.first;
                interval[1]=curr.second;
                ans.push_back(interval);
        
        return ans;
    }
};