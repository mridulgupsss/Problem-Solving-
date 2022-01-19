class Solution {
public:  // optimizing using KMP algorithm:
    string reverse(string &s){
        string str="";
        for(int i=s.size()-1; i>=0; i--){
            str.push_back(s[i]);
        }
        return str;
    }
    string shortestPalindrome(string s) {
        int m=s.size();
        string str="";
        str+=s+"#"+ reverse(s);
       
        
        int n=str.length();
        int arr[n];
        int i=1, len=0; arr[0]=0;
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
        
        int sz=m-arr[n-1];
        string ans ="";
        int j=m-1;
        while(sz--){
            ans+=s[j];
            j--;
        }
        ans+=s;
         return ans;
        
        
    }
};