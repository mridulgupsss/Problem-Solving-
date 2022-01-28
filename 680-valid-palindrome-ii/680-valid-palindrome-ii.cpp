class Solution {
public:
    bool isPalin(string s, int i, int j){
      
        while(i<j){
            if(s[i]==s[j]){
                i++; j--;
            }
            else return false;
            
        }
        return true;
    }
    bool validPalindrome(string s) {
            int i=0, j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++; j--;
            }
            else return (isPalin( s,  i+1,  j) || isPalin(s, i, j-1));
            
        }
        
        return true; 
    }
};