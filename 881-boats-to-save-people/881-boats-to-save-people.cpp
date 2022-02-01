class Solution {
public: // Using bucket sort it can be done in O(N) time:
    int numRescueBoats(vector<int>& people, int limit) {
        /* nlogn is occuring due to sorting and we know that every person can go on boat so array of people cannot contain element greater than the limit , so we can use bucket sort to reduce sorting complexity and then using the pointer approach on the count array; 
        */
        
      int ans =0;
      vector<int> count (limit+1, 0);
        for(auto val: people ){
            count[val]++;
        }
         // now 2 pointer on count array;
        int i=0, j=limit;
        while(i<=j){
            if(count[i]==0) i++;
            else if(count[j]==0) j--;
            else{
                if(i==j && count[i]==1){
                    ans++; break;
                }
                else if(i+j<=limit){
                    count[i]--; count[j]--;
                    ans++;
                    cout<<ans;
                }
                else {
                    count[j]--; ans++;
                }
            }
        }
        return ans;
    }
};