class Solution {
public:
    bool isSafe(int i, int j, vector<string>&smallAns, int n)
    {
        // vertical up
        for(int a=i-1; a>=0; a--)
        {
            if(smallAns[a][j]=='Q')
                return false;
            
        }
        
        //diagonal left
        for(int a=j-1, b=i-1; a>=0 && b>=0; a--,b--)
        {
            if(smallAns[b][a]=='Q')
                return false;
        }
        
        //diagonal right
        for(int a=j+1, b=i-1; a<n && b>=0; a++,b--)
        {
            if(smallAns[b][a]=='Q')
                return false;
        }
        return true;
    }
   
    void helper(vector<string>&smallAns, int n,vector<vector<string>>&ans, int row)
    {
        if(row==n) // base case
        {
         ans.push_back(smallAns);
            return;
        }
        
        for(int col=0; col<n; col++)
        {
           if(isSafe(row, col, smallAns, n)==true)
           {
            smallAns[row][col]='Q';
            helper(smallAns, n, ans, row+1);
            smallAns[row][col]='.';
           }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        vector<string> smallAns(n,str);
        vector<vector<string>> ans;
        helper(smallAns, n, ans, 0);
        return ans;
    }
};