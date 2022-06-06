class Solution {
public:
    // https://www.youtube.com/watch?v=emF5eAYR3Nk
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans ;
        map<int, vector<int>> mp;
        for(auto it: adjacentPairs){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int head;
        for(auto it: mp){
            if(it.second.size()==1) {
                head=it.first; break;
            }
        }
        int n = adjacentPairs.size()+1;
        int sz=0;int prev=-1;
        while(sz<n){
          ans.push_back(head);
            sz++;
            int temp=head;
            vector<int> vec = mp[head];
            if(vec.size()==1) head=vec[0];
            else 
            head= vec[0]!=prev?vec[0]:vec[1];
            prev=temp;
        }
        return ans;
    }
};