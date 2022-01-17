class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int lo=0, hi=n-1;
        

        while(lo<=hi){
            n=hi-lo+1;
            if(n==1) return lo;
            if(arr[lo]>arr[lo+1]) return lo;
            if(arr[hi]>arr[hi-1]) return hi;
            
             int m=(lo+hi)/2;
             if(arr[m]>arr[m-1] && arr[m]>arr[m+1]) return m;
             else if(arr[m]>arr[m-1]) lo=m+1;
             else if(arr[m]>arr[m+1]) hi=m-1;
             else lo=m+1; // anhalf can be taken 
        }
        
          return 0; // faaltu
        }
};