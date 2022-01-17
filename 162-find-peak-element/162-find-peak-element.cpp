class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int lo=0, hi=n-1;
        

        while(lo<hi){
             int m=(lo+hi)/2;
             if(arr[m]<arr[m+1]) lo=m+1;
             else hi=m;
        }
        
          return lo; 
        }
};