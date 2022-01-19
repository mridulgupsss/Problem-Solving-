class Solution {
public:
    int fun(vector<int>& arr, int distance){
        int ballsPlaced=1; // at arr[0]
        int prev=arr[0];
        for(int i=1; i<arr.size(); i++){
            if(arr[i]-prev>=distance){
               prev=arr[i]; // new ball placed here
                ballsPlaced++;
            }

        }
        
        return ballsPlaced;
        
    }
    int maxDistance(vector<int>& arr, int m) {
          int maxx=INT_MIN, minn=INT_MAX;
        sort(arr.begin(), arr.end());
        for(auto v:arr){
            maxx=max(maxx, v);
            minn=min(minn, v);
            
        }
        
        int lo=1, hi=maxx-minn; int ans;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(fun(arr, mid)<m){
                hi=mid-1;
            }
            else{
                ans=mid; // potential ans
                lo=mid+1;
            }
        }
        return ans;
    }
};