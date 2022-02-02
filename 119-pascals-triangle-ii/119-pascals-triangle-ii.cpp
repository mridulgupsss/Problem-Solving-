class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // row = rowIndex, col=0 to row
        
        vector<int> ans;
        int iCj=1; // ic0=1;
        for(int j=0; j<=rowIndex; j++){
            ans.push_back(iCj);
            iCj=iCj*1LL*(rowIndex-j)/(j+1);
        }
        return ans;
        
    }
};