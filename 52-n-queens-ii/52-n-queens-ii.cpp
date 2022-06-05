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
   
    void helper(vector<string>&smallAns, int n,int* ans, int row)
    {
        if(row==n) // base case
        {
         *ans=*ans+1;
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
    int totalNQueens(int n) {
        int answer =0;
        string str(n,'.');
        vector<string> smallAns(n,str);
      
        helper(smallAns, n, &answer, 0);
        return answer;
    }
};