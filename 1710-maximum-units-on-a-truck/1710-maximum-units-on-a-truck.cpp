class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& arr, int n){
       sort(arr.begin(), arr.end(), comp);
        int ans =0;
        for(auto vec: arr){
            if(n==0) break;
            if(n>=vec[0]){
                n-=vec[0];
                ans+=vec[1]*vec[0];
            }
            else{
                ans+=n*vec[1];
                break;
            }
        }
        
        return ans;
    }
};