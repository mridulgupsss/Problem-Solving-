class Solution {
public:  
    // solution explained : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/1576116/C%2B%2Bor-Binary-Search-on-Answers-(A-very-imp.-Topic)or-Easy-explanation
    
    int fun(vector<int> &arr, int capacity){
        int sum=0; int days=1;
        for(auto val:arr){
         
            if(sum+val<=capacity){
                sum+=val;
            }
            else {
                days++;
                sum=val;
            }
        }
        return days;
    }
    
    
    int shipWithinDays(vector<int>& arr, int days) {
        int sum=0; int maxx=INT_MIN;
        int ans;
        for(auto  val:arr){
            sum+=val;
            maxx=max(maxx, val);
        }
        int lo=maxx, hi=sum;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(fun(arr, mid) <= days){
                ans=mid;
                hi=mid-1;
                
            }
            else {
                lo=mid+1;
                
            }
        }
        
        return ans;
    }
};