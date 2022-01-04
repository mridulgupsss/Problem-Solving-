class Solution {
public:
    //Memoization 
    int helper(string &word1, string &word2, int i, int j, int **mem)
    {
        int n = word1.size(), m = word2.size();
        
        // base case:
          if(i==n ) return m-j;
        if(j==m) return n-i;
        
        // memoized data
        if(mem[i][j]!=-1)
        return mem[i][j];
        
        // calls
        if(word1[i]==word2[j])
        {
            return helper(word1, word2, i+1, j+1, mem);
        }
        // else
        
            int ans=INT_MAX;
        
            //replace:
             ans=min (ans, helper(word1, word2, i+1, j+1, mem) +1);
            
            // delete
             ans=min (ans, helper(word1, word2, i+1, j, mem) +1) ;
            
            //insert
             ans=min (ans, helper(word1, word2, i, j+1, mem) +1 );
        
        mem[i][j]=ans;
        return ans;
    }
    int minDistance(string word1, string word2) {
        
          int n = word1.size(), m = word2.size();
        // memoized data storage
        int **dp = new int*[n];
        for(int i=0; i<n; i++)
        {
            dp[i]=new int[m];
        }
        for(int i=0; i<word1.size(); i++)
        {
            for(int j=0; j<word2.size(); j++)
            {
                dp[i][j]=-1;
            }
        }
        
        
        return helper(word1, word2, 0 , 0, dp);
    }
};