class Solution {
public:  // O(n) solution discuss section
    vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr;
        
        bool a = arr[0]<arr[1];
        for(int i=1; i<n-1; i++){
            if((a && arr[i+1]>arr[i]) || (!a && arr[i+1]<arr[i])){
                swap(arr[i], arr[i+1]);
            }
            a=!a;
        }
        
        return arr;
    }
};