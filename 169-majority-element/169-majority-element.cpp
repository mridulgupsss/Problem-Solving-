class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0, ele=0;
        for(auto val: nums){
            if(cnt==0){
                ele=val;
                cnt++;
            }
            else{
                if(ele==val) cnt++;
                else cnt--;
            }
        }
        return ele;
    }
};