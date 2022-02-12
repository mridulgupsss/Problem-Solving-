class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &a,auto&b)->bool{
            return a[1]<b[1];
        }); // sorting according to end points 
        
        int curr=points[0][1];
        int arrows=1;
        for(int i=1; i<points.size(); i++){
            int st = points[i][0];
            int end = points[i][1];
            if(st>curr){
                arrows++;
                curr=end;
            }
        }
        
        return arrows;
    }
};