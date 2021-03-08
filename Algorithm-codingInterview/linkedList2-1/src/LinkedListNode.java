
public class LinkedListNode {
	LinkedListNode previous = null;
	LinkedListNode next = null;
	int data;
	
	public LinkedListNode(int d) {
		data = d;
	}
	void appendToTail(int d) {
		LinkedListNode end = new LinkedListNode(d);
		LinkedListNode n = this;
		while(n.next!=null) {
			n = n.next;
		}
		end.previous = n;
		n.next = end;
	}
}
