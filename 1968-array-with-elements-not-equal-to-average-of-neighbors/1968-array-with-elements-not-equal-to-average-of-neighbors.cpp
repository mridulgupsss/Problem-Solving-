class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
    vector<int> ans(n);
        int b=n-1;
        int a=0;
        int i=0;
        while(i<n){
            if(i%2==0){
                ans[i++]=arr[a++];
                
            }
            else{
                ans[i++]=arr[b--];
            }
        }
        
        return ans;
    }
};