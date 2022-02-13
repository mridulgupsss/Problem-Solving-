class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        // already sorted form intervals;;
        vector<vector<int>> ans;
        int i=0, j=0;
        while(i<firstList.size() && j<secondList.size()){
            int st1 = firstList[i][0];
            int end1 = firstList[i][1];
            
            int st2 = secondList[j][0];
            int end2 = secondList[j][1];
            
            int common_st = max(st1, st2);
            int common_end = min(end1, end2);
            
            if(common_end < common_st){
                if(end1<end2) i++;
                else j++;
            }
            else{
                vector<int> small_ans(2);
                small_ans[0]=common_st;
                small_ans[1]=common_end;
                ans.push_back(small_ans);
                
                if(end1<end2) i++;
                else j++;
            }
        }
        
        return ans;
    }
};