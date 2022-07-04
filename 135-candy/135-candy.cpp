class Solution {
public:
    int candy(vector<int>& ratings) {
        int n =ratings.size();
        if(n==1) return 1;
        vector<int> ans (n, 1);
    
      
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1] ){
                ans[i]=ans[i-1]+1;

            }

           
        }
        vector<int> ans2 (n, 1);
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1] ){
                ans2[i]=ans2[i+1]+1;

            }

           
        }
        int x=0;
        for(int i=0; i<n; i++){
            x+=max(ans[i], ans2[i]);
        }
        
        
        
        return x;
    }
};