class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow=0, fast=0;
        while(true){
            slow = arr[slow]; // next
            fast = arr[arr[fast]]; // next to next
            
            if(slow==fast)
                break;
            
        }
        slow=0;
        
        while(slow!=fast){
            slow=arr[slow]; // next
            fast=arr[fast]; // next
        }
        
        return slow;

        
    }
};