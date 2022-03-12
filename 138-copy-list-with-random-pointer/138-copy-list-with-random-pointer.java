/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node curr=head;
        
        // attaching new nodes after every original node
        while(curr!=null)
        {
            Node node =new Node(curr.val);
            Node temp=curr.next;
            curr.next=node;
            node.next=temp;
            curr=temp;
        }
        
        // filling random pointer of new nodes 
        curr=head;
        while(curr!=null)
        {
            
            if(curr.random!=null)
                curr.next.random=curr.random.next;
            else
                curr.next.random=null;
            
            curr=curr.next.next;
            
        }
        
        
        // extracting out linked list of new copy nodes
        curr=head;
        Node dummy =new Node(-1);
        Node ptr=dummy;
        while(curr!=null)
        {
            ptr.next=curr.next;
            ptr=ptr.next;
            curr.next=ptr.next;
            curr=curr.next;
            ptr.next=null;
        }
        
        return dummy.next;
    }
}