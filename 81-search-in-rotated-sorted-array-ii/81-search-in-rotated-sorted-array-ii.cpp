class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n= arr.size();
        int lo =0, hi=n-1;
        while(lo<=hi){
            while (lo < hi && arr[lo] == arr[lo + 1]) {
                lo++;
            }
            while (lo < hi && arr[hi] == arr[hi - 1]) {
                hi--;
            }
            int mid=(lo+hi)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]>=arr[lo]){  // left portion sorted
                if(target<=arr[mid] && target>=arr[lo]) hi=mid-1;
                else lo=mid+1;
            }
            else {  // right portion sorted 
                if(target>=arr[mid] && target<=arr[hi]) lo=mid+1;
                else hi=mid-1; 
            }
        }
        
        return false;
    }
};