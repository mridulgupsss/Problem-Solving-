class Solution {
public:
    int furthestBuilding(vector<int>& arr, int bricks, int ladders) {
        int n=arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n-1; i++){
            if(arr[i+1]>arr[i]){
                int diff=arr[i+1]-arr[i];
                pq.push(diff);
                if(pq.size()==ladders+1){
                    int jump= pq.top(); pq.pop();
                    if(bricks - jump>=0){
                        bricks-=jump;
                    }
                    else{
                        return i;
                    }
                }
            }
        }
        
        return n-1;
    }
};