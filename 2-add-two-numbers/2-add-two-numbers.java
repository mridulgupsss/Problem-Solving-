/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
 
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // given already reversed
        int c=0; 
        ListNode dummy=new ListNode(-1), ptr=dummy;
        while(l1!=null || l2!=null)
        {
            int sum = c + (l1!=null?l1.val:0) + (l2!=null?l2.val:0);
            int digit = sum%10;
            c=sum/10;
            
            ptr.next=new ListNode(digit);
            ptr=ptr.next;
            
            l1=l1!=null?l1.next:null;
            l2=l2!=null?l2.next:null;
        }
        if(c!=0)
        {
            ptr.next=new ListNode(c);
        }
        
        return dummy.next;
    }
}