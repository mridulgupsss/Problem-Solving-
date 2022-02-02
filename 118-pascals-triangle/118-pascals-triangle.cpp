class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int> smallAns;
            int iCj=1; //i_C_0=1;
            for(int j=0; j<=i; j++){
                smallAns.push_back(iCj);
                int iCj_plus_1 = iCj*(i-j)/(j+1);
                iCj=iCj_plus_1;
            }
            ans.push_back(smallAns);
        }
        
        return ans;
    }
};