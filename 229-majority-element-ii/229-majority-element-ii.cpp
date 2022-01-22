class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0, cnt2=0, ele1=0, ele2=0;
        for(auto val: nums){
            if(cnt1==0 && val!=ele1 && val!=ele2){
                ele1=val;
                cnt1++;
            }
            else if(cnt2==0 && val!=ele2 && val!=ele1){
                ele2=val;
                cnt2++;
            }
            else{
                if(val==ele1) cnt1++;
                else if(val==ele2) cnt2++;
                else {
                     cnt1--; // cnt2-- can also be written
                     cnt2--;
                }
            }
        }
        
        cnt1=0, cnt2=0;
        for(auto val : nums){
            if(val==ele1) cnt1++;
            else if (val==ele2) cnt2++;
        }
        int n=nums.size();
        vector<int> ans;
        if(cnt1>n/3) ans.push_back(ele1);
        if(cnt2>n/3) ans.push_back(ele2);
        
        return ans;
    }
};