class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end()); 
        
        int curr1=points[0][0];
        int curr2=points[0][1];
        int arrows=1;
        for(int i=1; i<points.size(); i++){
            int st = points[i][0];
            int end = points[i][1];
            if(st>curr2){
                arrows++;
                curr1=st;
                curr2=end;
            }
            else{
                if(end<=curr2){
                    curr1=st;
                    curr2=end;
                }
                else{
                    curr1=st;
                    
                }
            }
        }
        
        return arrows;
    }
};