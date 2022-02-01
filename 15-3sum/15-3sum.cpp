class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
         vector<vector<int>>  ans;
        int k=0;
        while(k<=n-3){
       
            int  i=k+1, j=n-1;

            
            while(i<j){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> v;
                    v.push_back(arr[k]);
                    v.push_back(arr[i]);
                    v.push_back(arr[j]);
                    
                    ans.push_back(v);
                    
                    int ival=arr[i], jval=arr[j];
            while(i<n && ival==arr[i]) i++;
               
                while( j>=0 && jval==arr[j]) j--;

                }
                else if(arr[i]+arr[j]+arr[k]<0){
                    int ival=arr[i];
                            while(i<n && ival==arr[i]) i++;
                }
                else{
                    int jval=arr[j];
                    while(j>=0 && jval==arr[j]) j--;
                }
            }
            
           int kval=arr[k];
            while(k<n && arr[k]==kval) k++;
            
            
        }
        
        return ans;
    }
};