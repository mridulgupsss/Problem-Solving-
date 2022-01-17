class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(), m=arr2.size();
          if(n>m) return findMedianSortedArrays(arr2, arr1);
         // if(n!=0 && m!=0)
         // {
         //     if(arr1[0]>arr2[m-1]) return findMedianSortedArrays(arr2, arr1);// to handle cases like [4,5], [2,3]
         // }
        double ans;
        int total=n+m;
        int lo=0, hi=n;

        while(lo<=hi){
            int cut1=(lo+hi)/2;
            int cut2=(n+m+1)/2 -cut1;
            
            int left1 = cut1==0 ? INT_MIN : arr1[cut1-1];
            int left2 = cut2==0 ? INT_MIN : arr2[cut2-1];  // to handle cases like [1], [2]  maybe even cases 
            
            int right1 = cut1==n ? INT_MAX : arr1[cut1];
            int right2 = cut2==m ? INT_MAX : arr2[cut2];
            
            if(left1<=right2 && left2<=right1){
                // ans
                if(total%2==0){
                    int l= max(left1, left2);
                    int r= min(right1, right2);
                    ans=(l+r)/2.0;
                }
                else {
                    ans=max(left1, left2);
                }
                
                
                break;
                
            }
            else if (left1>right2){
                hi=cut1-1;
            }
            else if(left2>right1){
                lo=cut1+1;
            }
            
        }
        
        return ans;
    }
};