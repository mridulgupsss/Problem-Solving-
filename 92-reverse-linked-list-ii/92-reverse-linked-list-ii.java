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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(head==null || head.next==null) return head;
        ListNode leftbefore=null, rightafter=null;
        ListNode ptr=head, prev=null;
         ListNode tempHead=null, tempTail=null;
        for(int i=1; i<=right; i++)
        {
            if(i==left)
            {
              leftbefore=prev;  
                
            }
            if(i==right)
            {
                rightafter=ptr.next;
            }
            prev=ptr;
            ptr=ptr.next;
        }
        
        ListNode newHead=null;
        if(leftbefore!=null)
       newHead=leftbefore.next;
       else
           newHead=head;
        
        ListNode curr=newHead, fwd=curr.next;
        int size=right-left+1;
        while(size-->0)
        {
            curr.next=null;
            if(curr==newHead)
            {
                tempHead=curr; tempTail=curr;
            }
            else
            {
                curr.next=tempHead;
                tempHead=curr;
            }
            curr=fwd; 
            if(fwd!=null) fwd=fwd.next;
        }
        
        if(leftbefore!=null)
        {
            leftbefore.next=tempHead;
        }
        tempTail.next=rightafter;
        if(left==1)
        {
            return tempHead;
        }
        else
        {
            return head;
        }
    }
}