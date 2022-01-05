class Solution {
public:
    int helper(string &s, int i, int j, int **mem)
    {
        // base case :
        if(i>j) return 0;
        if(i==j) return 1; // very important base case
        
        if(mem[i][j]!=-1) return mem[i][j];
        
        // calls
        char c1=s[i], c2=s[j];
        if(c1==c2)
        {
             mem[i][j]= helper(s, i+1, j-1, mem)+2;
            return mem[i][j];
        }
        // else
        mem[i][j]=max(helper(s, i, j-1, mem), helper(s, i+1, j, mem));
        return mem[i][j];
        
    }
    int longestPalindromeSubseq(string s) {
        // memoization
        int n=s.length();
        int **mem=new int*[n];
        for (int i=0; i<n; i++)
        {
            mem[i]=new int[n];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mem[i][j]=-1;
            }
        }
        return helper(s, 0, n-1, mem);
    }
};