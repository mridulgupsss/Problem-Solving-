class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i=1, n=arr.size();
        int ct=1; int k=1; int val=arr[0];
        while(i<n){
            if(arr[i]==val){
                ct++;
                if(ct<=2){
                    arr[k++]=val;
                }
            }
            else{
                ct=1;
                val=arr[i];
                arr[k++]=val;
                
            }
            i++;
            
        }
        
        return k;
    } 
};




