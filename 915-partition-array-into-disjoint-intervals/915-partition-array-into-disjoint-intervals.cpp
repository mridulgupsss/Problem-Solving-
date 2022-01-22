class Solution {
public:  // without space *** is important :
    int partitionDisjoint(vector<int>& arr) {
        int cut_idx=0; // after 0
        int minn=arr[1], maxx=arr[0], maxx2=arr[0];
        for(int i=1; i<arr.size()-1; i++){
            minn=min(minn, arr[i]);
            if(minn<maxx){
                cut_idx=i;
                minn=arr[i+1]; // partition here
                maxx=max(maxx2, arr[i]);
            }

            
            maxx2=max(maxx2, arr[i]);
        }  
        return cut_idx+1;
    }
};