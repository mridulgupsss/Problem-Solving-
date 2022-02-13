class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n==0){
            ans.push_back(newInterval);
            return ans;
        }
        int index;
        int st= newInterval[0], end= newInterval[1];
        for(int i=0; i<intervals.size(); i++){
            int st1 = intervals[i][0];
            int end1 = intervals[i][1];
            
            // considering all 6 cases
            
            if(st>=st1){
                if(st>end1){
                    ans.push_back(intervals[i]);
                    if(i==n-1){
            newInterval[0]=st; newInterval[1]=end;
            ans.push_back(newInterval);
                    }
                }
                else if(end>end1){
                    st=st1;
                    if(i==n-1){
            newInterval[0]=st; newInterval[1]=end;
            ans.push_back(newInterval);
                    }
                }
                else{
                    ans.push_back(intervals[i]);
                    index=i+1;
                    break;
                }
                
            }
            else{
                if(end<st1){
                    index=i;
                        vector<int> small;
                    small.push_back(st);
                    small.push_back(end);
                    ans.push_back(small);
                    break;
                }
                else if(end<=end1){
                    end=end1;
                    if(i==n-1){
            newInterval[0]=st; newInterval[1]=end;
            ans.push_back(newInterval);
                    }
                }
                else{
                    // nothing to do
                    if(i==n-1){
            newInterval[0]=st; newInterval[1]=end;
            ans.push_back(newInterval);
                    }
                }
            }
        }

        while(index<intervals.size()){
            ans.push_back(intervals[index++]);
        }
        
        return ans;
    }
};