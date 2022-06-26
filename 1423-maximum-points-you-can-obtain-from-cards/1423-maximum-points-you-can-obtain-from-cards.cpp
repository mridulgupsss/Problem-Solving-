class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         int n = cardPoints.size();
        int sz=n-k;
        int s=0, sum=0;// sum=total sum of array
        
        for(int i=0; i<n; i++){
                sum+=cardPoints[i];
        }
        
            if(n==k){
                return sum;
            }
        
        for(int i=0; i<sz-1; i++){
            s+=cardPoints[i];
            
            
        }
        int ans =INT_MAX;
        for(int j=0,i=sz-1; i<n; i++, j++){
            s+=cardPoints[i];
            ans=min(ans, s);
            s-=cardPoints[j];
            
            
        }
        
        return sum-ans;
    }
};