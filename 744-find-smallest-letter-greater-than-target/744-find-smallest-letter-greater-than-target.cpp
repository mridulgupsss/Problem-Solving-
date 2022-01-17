class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        int ans=arr[0];
        int lo=0; int hi=arr.size()-1;
        while(lo<=hi){
         int mid=(lo+hi)/2 ;
            if(arr[mid]>target){
                ans=arr[mid]; //potential
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        
        return ans;
    }
};