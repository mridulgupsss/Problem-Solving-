class Solution {
public: // optimized using KMP
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string str = goal + "#" + s + s;
    int i=1, len=0, n=str.length(); 
         int arr[n]; arr[0]=0;
        
        while(i<n){
            if(str[i]==str[len]){
                len++;
                arr[i]=len;
                i++;
            }
            else{
                if (len>0) len=arr[len-1];
                else{
                    arr[i]=0;
                    i++;
                }
                
            }
        }
        
        for(int j=0; j<n; j++){
           if(arr[j]==goal.size()) {
               return true;
           }
        }
        return false;
    
    }
    
};