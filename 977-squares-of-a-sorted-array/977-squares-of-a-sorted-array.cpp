class Solution {
public:  // O(N) time even if negitive elements are a;lso there ;
    vector<int> sortedSquares(vector<int>& arr) {
        int i=0;
        for(auto val: arr){
            if(val<0) i++;
        }
        
        int j=i-1;
        vector<int> v;
        while(j>=0 && i<arr.size()){
            int val1=arr[j]*arr[j];
            int val2=arr[i]*arr[i];
            if(val1<val2){
                j--;
                v.push_back(val1);
            }
            else{
                i++;
                v.push_back(val2);
            }
        }
        
        while(j>=0){
            v.push_back(arr[j]*arr[j]);
            j--;
        }
        
        while(i<arr.size()){
            v.push_back(arr[i]*arr[i]);
            i++;
        }
        
        
        return v;
    }
};