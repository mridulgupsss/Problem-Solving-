class Solution {
public:// memoization:  3D DP
    int helper(string &s1, string &s2, int si1, int si2, int len, vector<vector<vector<int>>> &mem)
    {
        
        // base case:
        if(s1.substr(si1, len)==s2.substr(si2, len)) {
            mem[si1][si2][len]=1;
            return 1;
        }
        
        if(mem[si1][si2][len]!=-1) return mem[si1][si2][len];
        //calls:
        for(int cut=0; cut<=len-2; cut++){
            if((helper(s1, s2, si1, si2, cut+1, mem) && helper(s1, s2, si1+cut+1, si2+cut+1, len-cut-1, mem)) || (helper(s1, s2, si1, si2+len-(cut+1), cut+1, mem) && helper(s1, s2, si1+cut+1, si2, len-cut-1, mem)) ==1) {
                mem[si1][si2][len]=1; return 1;
            }        
        }
        mem[si1][si2][len]=0;
        return 0;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.length(); // s1 and s2 same length given
        vector<vector<vector<int>>>mem(n, vector<vector<int>>(n, vector<int>(n+1)));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<=n; k++)
                {
                    mem[i][j][k]=-1;
                }
            }
        }
        if(helper(s1, s2, 0, 0, n, mem)==0) return false;
        return true;
    }
};