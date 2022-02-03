class Solution {
public:
    string getHappyString(int n, int k) {
        int total=3; // for n=1;
        for(int i=2; i<=n; i++){
            total*=2;
        }
        
        if(k>total) return ""; 
        string ans="";
        int calls=3;
        while(n>0){
            int parts = total/calls;
            int call = (k-1)/parts;
            
            if(calls==2){
                if(ans[ans.size()-1]=='a'){
                    cout<<call<<endl;
                    if(call==0) call=1; //b
                    else if(call==1) call=2; //c
                }
                else if(ans[ans.size()-1]=='b'){
                  
                    if(call==1) call=2; //c
                }
                else if(ans[ans.size()-1]=='c'){
                   // nothing to do
                }
            }
            if(call==0) ans+="a";
            else if(call==1) ans+="b";
            else if(call==2) ans+="c";
            
            total=total/calls;
            k=k%total;
            if(k==0)k=total;
            
            if(calls=3) calls=2;
            
            n--;
        }
        
        return ans;
    }
};