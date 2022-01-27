class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int i=0, j=0;
        while(i<arr.size()){
            if(arr[i]%2==0){
                swap(arr[i], arr[j]);
                i++; j++;
            }
            else{
                i++;
            }
        
    }
        
        return arr;
    }
};