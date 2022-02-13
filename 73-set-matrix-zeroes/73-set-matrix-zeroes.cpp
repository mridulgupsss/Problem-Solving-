class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int row =0, col=0;
        int n=arr.size(); int m=arr[0].size();
        for(int i=0; i<n; i++){
            if(arr[i][0]==0){
                col=1;
                break;
            }
        }
        
        for(int i=0; i<m; i++){
            if(arr[0][i]==0){
                row=1;
                break;
            }
        }
        
        
        for(int i=1; i<n; i++){
            for (int j=1; j<m; j++){
                if(arr[i][j]==0){
                    arr[i][0]=0;
                    arr[0][j]=0;
                }
            }
        }
        
        
        for(int i=1; i<n; i++){
            if(arr[i][0]==0){
                for(int j=1; j<m; j++){
                    arr[i][j]=0;
                }
            }
        }
        
        for(int j=1; j<m ; j++){
            if(arr[0][j]==0){
                for(int i=1; i<n; i++){
                    arr[i][j]=0;
                }
            }
        }
        
        if(col==1){
            for(int i=0; i<n; i++){
                arr[i][0]=0;
            }
        }
        
        if(row==1){
            for(int j=0; j<m; j++){
                arr[0][j]=0;
            }
        }
    }
};