class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n=name.size(), m=typed.size();
        int i=0, j=0;
        if(name[i++]!=typed[j++])return false;
       
        while(i<n && j<m ){
            if(name[i]==typed[j]){
                i++; j++;
            }
            else{
                if(typed[j]==name[i-1]){
                    j++;
                  
                }
                else return false;
            }
        }
        while(j<m){
            if(typed[j]==typed[j-1]) j++;
            else break;
        }
        if(j<m || i<n) return false;
        return true;
    }
};