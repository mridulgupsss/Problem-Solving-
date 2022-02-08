class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x=0, y=0;
        for(auto val: arr1){
            x^=val;   
        }
        for(auto val: arr2){
            y^=val;
        }
        return x&y;
        
    }
};