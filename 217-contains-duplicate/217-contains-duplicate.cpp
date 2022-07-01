class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        for(auto v: nums){
            st.insert(v);
        }
        if(st.size()!=nums.size()) return true;
        return false;
    }
};