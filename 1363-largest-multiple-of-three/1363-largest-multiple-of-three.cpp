class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
       sort(digits.begin(), digits.end());
        int n=digits.size();
        
        int sum=0;
        for(auto val : digits){
            sum+=val;
        }
        string ans=""; 
        if(sum%3==0){
            for(auto val: digits){
                ans+=val+'0';
            }
        }
        else{
            int one=0, two=0;
            for(int i=0; i<n; i++){
                if(digits[i]%3==1)one++;
                else if(digits[i]%3==2) two++;
            }
            int flag;
            if(sum%3==1){
              if(one==0){
                  flag=0;
                  for(auto val: digits){
                      if(val%3==2 && flag<2){
                          flag++; continue;
                      }
                      ans+=val+'0';
                  }
              }
                else{
                    flag=1;
                  for(auto val: digits){
                      if(val%3==1 && flag<2){
                          flag++; continue;
                      }
                      ans+=val+'0';
                  }
                }
            }
            else{
            
              if(two==0){
                  flag=0;
                  for(auto val: digits){
                      if(val%3==1 && flag<2){
                          flag++; continue;
                      }
                      ans+=val+'0';
                  }
              }
                else{
                    flag=1;
                  for(auto val: digits){
                      if(val%3==2 && flag<2){
                          flag++; continue;
                      }
                      ans+=val+'0';
                  }
                }                

            }
            
 
        }           
        
        
        reverse(ans.begin(),ans.end());
        if(ans.size()>0)
        if(ans[0]=='0') return "0";
        return ans;
    }  
};