class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        int i=1, j=0;
        int ans =1; int small_ans=1;
        unordered_set<char> st;
            st.insert(s[0]);    
        while(i<n){
           if(st.find(s[i])!=st.end()){
               while(s[j]!=s[i]){
                   st.erase(s[j]);
                   j++;
               }
               j++;
               small_ans = i-j+1;
           }
            else{
                st.insert(s[i]);
                small_ans++;
                ans=max(ans, small_ans);

            }
            
            
            i++;
        }
        
        return ans;
    }
};