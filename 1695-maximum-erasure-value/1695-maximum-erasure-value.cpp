class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr) {
        int sum=0; 
        unordered_set<int> st; int ans =0;
        for(int i=0, j=0; i<arr.size(); i++){
            // acquire :
            sum+=arr[i];
            
            // work
            if(st.find(arr[i])!=st.end()){
                while(arr[j]!=arr[i]){
                    sum-=arr[j];
                    st.erase(arr[j]);
                    j++;
                }
                sum-=arr[j];
                j++;
            }
            else{
                st.insert(arr[i]);
                ans=max(ans, sum);
            }
        }
        
        return ans;
    }
};