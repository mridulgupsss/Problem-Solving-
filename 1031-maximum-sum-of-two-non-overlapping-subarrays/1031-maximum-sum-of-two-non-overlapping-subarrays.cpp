class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& arr, int len1, int len2) {
        int n=arr.size();
        int sum=0;
        int prefix1[n]; int mxx=INT_MIN;
        for(int i=0; i<n; i++){
            
            if(i<len1-1){
                 prefix1[i]=0;
                sum+=arr[i];
            }
            else{
                sum+=arr[i];
                mxx=max(mxx, sum);
                prefix1[i]=mxx;
                sum-=arr[i-len1+1];
            }
        }
        sum=0;
          int prefix2[n]; mxx=INT_MIN;
        for(int i=0; i<n; i++){
            
            if(i<len2-1){
                 prefix2[i]=0;
                sum+=arr[i];
            }
            else{
                sum+=arr[i];
                mxx=max(mxx, sum);
                prefix2[i]=mxx;
                sum-=arr[i-len2+1];
            }
        }
        sum=0;
          int suffix2[n]; mxx=INT_MIN;
        for(int i=n-1; i>=0; i--){
            
            if(i>n-len2){
                 suffix2[i]=0;
                sum+=arr[i];
            }
            else{
                sum+=arr[i];
                mxx=max(mxx, sum);
                suffix2[i]=mxx;
                sum-=arr[i+len2-1];
            }
        }
        sum=0;
          int suffix1[n]; mxx=INT_MIN;
        for(int i=n-1; i>=0; i--){
            
            if(i>n-len1){
                 suffix1[i]=0;
                sum+=arr[i];
            }
            else{
                sum+=arr[i];
                mxx=max(mxx, sum);
                suffix1[i]=mxx;
                sum-=arr[i+len1-1];
            }
        }
        
        
        
        // ans
        mxx=INT_MIN;
        for(int i=0; i<n-1; i++){
            mxx=max({mxx, prefix1[i]+suffix2[i+1], prefix2[i]+suffix1[i+1]});
        }
        
        return mxx;
        
    }
};