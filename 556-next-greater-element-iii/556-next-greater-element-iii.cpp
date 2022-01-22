class Solution {
public:
    int nextGreaterElement(int n) {
    
        vector<int> v;
        while(n>0){
            v.insert(v.begin(), n%10);
            n=n/10;
        }
        
        int m=v.size();
        int i=m-1;
        while(i>=1){
            if(v[i]<=v[i-1]) i--;
            else{
              
                int k=m-1;
                while(k>=i){
                    if(v[k]>v[i-1]){
                        swap(v[i-1], v[k]);
                        break;
                    }
                    k--;
                }
                
                break;
            }
        }
        if(i==0) return -1;
        //else
            reverse(v.begin()+i, v.end());
            long long int ans=0;
        for(auto val: v){
            ans=ans*10 + val;
        }
        return ans>INT_MAX?-1:ans;
    }
};