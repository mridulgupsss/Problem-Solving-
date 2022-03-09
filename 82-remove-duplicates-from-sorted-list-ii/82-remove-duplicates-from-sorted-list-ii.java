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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode curr=head;
        ListNode dummy=new ListNode(-1);
        ListNode ptr=dummy;
        while(curr!=null)
        {
            boolean flag=true;
         while(curr.next!=null && curr.val==curr.next.val)
         {
             flag=false;
             curr=curr.next;
         }
            if(flag==false && curr!=null) curr=curr.next;

        if(flag==true)
        {
            ListNode frwd=curr.next;
            curr.next=null;
            ptr.next=curr;
            ptr=ptr.next;
            curr=frwd;
        }
        }
        return dummy.next;
    }
}