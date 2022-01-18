class Solution {
public:  
    
    // solution : Don't treat it as a 2D matrix, just treat it as a sorted list
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int lo=0, hi=n*m - 1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            
            // converting 1d to 2d array
            int row=mid/m;
            int col=mid%m;
            int val=matrix[row][col];
            if(val==target) return true;
            else if(val>target) hi=mid-1;
            else lo=mid+1;
            
        }
        return false;
    }
};