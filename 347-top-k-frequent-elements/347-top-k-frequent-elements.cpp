class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        vector<int> ans;
        int n=arr.size();
        unordered_map<int, int> m;
        for(auto v :arr){
            m[v]++;
        }
        vector<vector<int>> bucket(n);
        for(auto it: m){
            bucket[it.second-1].push_back(it.first);
        }
        int i=n-1;
        while(k>0 && i>=0){
            while(bucket[i].size()>0 && k>0){
                ans.push_back(bucket[i][bucket[i].size()-1]);
                bucket[i].pop_back();
                k--;
            }
            i--;
        }
        
        return ans;
    }
};