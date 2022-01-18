class Solution {
public:
      int diff(int mid, vector<int>& arr, int target)
        {
         int sum = 0;
         for(int i = 0; i < arr.size(); i++)
             sum += min(mid, arr[i]);
        
         return abs(target - sum);
        }
    
    
  int findBestValue(vector<int>& arr, int target)
    {
        int n = arr.size();
        int lo = 0;
        int hi = target;
        int ans;
       
        while(lo <= hi)
        {
            int mid = (lo+hi)/2;
            if(diff(mid, arr, target) <= diff(mid + 1, arr, target))
            {
                ans=mid;
                hi=mid-1;
            }
            else
                lo = mid + 1;
        }
        
        return ans;
        
        
    }
};