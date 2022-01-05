class Solution {
public: // backtracking pep
    bool isPalin(string s)
    {
        int n=s.size();
        int j=n-1, i=0;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(string &ques, vector<vector<string>>& ans, vector<string>& asf)
    {
        if(ques.size()==0)
        {
            ans.push_back(asf);
            return;
        }
        for(int n=1; n<=ques.size(); n++)
        {
            string prefix=ques.substr(0,n);
            if(isPalin(prefix)==true)
            {
                string roq="";
                if(n!=ques.size())
                {
                    roq=ques.substr(n);
                }
              
                    
                asf.push_back(prefix);
                helper(roq, ans, asf);
                asf.pop_back();
            }
        }
        return;
    }
    
    // given function 
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        helper(s, ans, v);
        return ans;
    }
};