class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            int ele=abs(arr[i]);
            int idx=ele-1;
            if(arr[idx]<0){
                ans.push_back(ele);
            }
            else{
                arr[idx]=-1*arr[idx];
                
            }
        }
        return ans;
    }
};