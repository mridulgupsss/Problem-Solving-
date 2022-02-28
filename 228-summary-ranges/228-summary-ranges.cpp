class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        int i = 0;
        while(i < nums.size()) {
            int j = min(i+1, INT_MAX);
            while(j < nums.size() && nums[j] == nums[j-1]+1) j++;
            j--;
            string temp = to_string(nums[i]);
            if(j != i) {
                temp += "->" + to_string(nums[j]);
            }
            res.push_back(temp);
            i = j+1;
        }
        return res;
    }
};