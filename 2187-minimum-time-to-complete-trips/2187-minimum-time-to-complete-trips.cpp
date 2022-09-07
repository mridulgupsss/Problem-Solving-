class Solution {
public:
    
    long long funct(vector<int>& time,long long t){
        long long ans=0;
        for(auto v: time){
          ans+=(t*1LL/v);    
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long int lo=1, hi=1e14;// important to understand the range
        long long ans;
        while(lo<=hi){
            long long mid=lo +(hi-lo)/2;
            long long trips= funct(time, mid);
            if(trips>=totalTrips){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        
        return ans;
    }
};