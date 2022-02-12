// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
       if(intervals.size()==0)  return ans;
        sort(intervals.begin(),intervals.end());
        pair<int,int> curr(intervals[0][0], intervals[0][1]);
         
        for(auto it : intervals){
            if(it[0]<=curr.second && it[1]>curr.second){
                curr.second=it[1];
            }
            else if(it[0]<=curr.second){
 // nothing to do skip this interval as it is complete;y overlapped
            }
            else{
                vector<int> interval(2);
                interval[0]=curr.first;
                interval[1]=curr.second;
                ans.push_back(interval);
                
                curr.first=it[0];
                curr.second=it[1];
            }
        }
        
                vector<int> interval(2);
                interval[0]=curr.first;
                interval[1]=curr.second;
                ans.push_back(interval);
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends