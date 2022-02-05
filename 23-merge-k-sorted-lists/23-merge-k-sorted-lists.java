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
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head=null;
        ListNode returning_head=null;
        
        PriorityQueue<ListNode> pq= new PriorityQueue<>((a,b)->a.val-b.val);
       
        for(ListNode node: lists)
        {
            if(node!=null)
            pq.add(node);
        }
        
        while(pq.size()>0)
        {
            ListNode curr=pq.remove();
            if(head==null)
            {
                head=curr;
                returning_head=head;
            }
            else
            {
                head.next=curr;
                head=head.next;
            }
            if(curr.next!=null)
            {
                pq.add(curr.next);            
            }
          
        }
        return returning_head;
        
    }
}