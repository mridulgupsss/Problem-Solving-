class Solution {
public:
    void wiggleSort(vector<int>& arr) {
        vector<int>  temp(arr.size()); 
 
        int n=arr.size();
        if(n==1) return;
        sort(arr.begin(), arr.end());

        int j=n-1;
        int i=1;
        while(j>=0){
            temp[i]=arr[j--];
            if(i==n-1 || i==n-2){
                i=0;
            }
            else i+=2;
        }
        
        for(int i=0; i<n; i++){
            arr[i]=temp[i];
        }
    }
};