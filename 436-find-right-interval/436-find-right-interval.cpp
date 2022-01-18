class Solution {
public:
// Solution Must see : https://leetcode.com/problems/find-right-interval/discuss/814263/c%2B%2B-Using-Map-And-Bainary-Search
    
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size());
        map<int, int> m;
        for(int i = 0; i < intervals.size(); i++)
            m[intervals[i][0]] = i;
        for(int i = 0; i < intervals.size(); i++) 
               ans[i]  = m.lower_bound(intervals[i][1])!=end(m)?m.lower_bound(intervals[i][1]) -> second:-1;
        return ans;
    }
};