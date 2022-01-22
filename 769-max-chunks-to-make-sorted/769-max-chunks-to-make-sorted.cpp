class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int minn[n];
        int temp=INT_MAX;
        for(int i=n-1; i>=0; i-- ){
           temp=min(temp, arr[i]);
            minn[i]=temp;
        }
        int maxx=arr[0]; 
        int cuts=1;  //before 0 index  by default 
        for(int i=1; i<n; i++){
            // cut before index i :
            if(minn[i]>=maxx){
                cuts++;
             }
            maxx=max(maxx, arr[i]);
        }
        return cuts;
        
    }
};