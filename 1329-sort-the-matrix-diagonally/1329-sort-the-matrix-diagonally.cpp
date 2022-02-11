class Solution {
public:
    
void fun(vector<vector<int>> &ans, vector<vector<int>> &mat, int i, int j, int n, int m){
       int a =i , b=j;
    vector<int> v(100, 0);
    while(i<n && j<m){
            v[mat[i][j]-1]++;
        i++; j++;
        }   
    int k=0;
    while(a<n && b<m){
        while( v[k]==0)k++;
            
            
                ans[a][b]=k+1;
                v[k]--;
                a++; b++;
            
    
    }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=n-1; i>=0; i--){
            fun(ans, mat, i, 0, n, m);
            
        }
        
        for(int j=0; j<m; j++){
            fun(ans, mat, 0, j, n, m);
        }
        
        return ans;
    }
};