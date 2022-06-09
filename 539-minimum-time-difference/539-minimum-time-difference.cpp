class Solution {
private:
    int timeDiff(string t1) {
        int hour = stoi(t1.substr(0, 2));
        int minutes = stoi(t1.substr(3, 2));

        return (hour*60 + minutes);
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> arr;
        for(auto str : timePoints){
            arr.push_back(timeDiff(str));
        }
        
        sort(arr.begin(), arr.end());
        int ans =INT_MAX;
        for(int i=0; i<arr.size()-1; i++){
            ans= min(ans, arr[i+1]-arr[i]);
        }
        ans=min(ans,arr[0]-arr[arr.size()-1]+24*60);
        return ans;
    }
};