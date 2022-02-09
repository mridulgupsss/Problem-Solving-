class Solution {
public:
    bool binSearch(int target, int lo, int hi, vector<int> &v){
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(v[mid]==target) return true;
            else if(v[mid]>target) hi=mid-1;
                else lo=mid+1;
        }
        
        return false;
    }
    int findPairs(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end()); int ans=0;
        int i=0; int n=arr.size();
        while(i<n){
            int val=arr[i];
            int target = k+val;
            
           if(binSearch(target, i+1, n-1, arr)==true) ans++; 
            
            while(i<n && arr[i]==val) i++;
        }
        
        return ans;
    }
};