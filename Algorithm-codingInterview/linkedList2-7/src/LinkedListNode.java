public class LinkedListNode {
	LinkedListNode previous = null;
	LinkedListNode next = null;
	int data;

	//public LinkedListNode() {}
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
	int length() {
		int num = 0;
		LinkedListNode n = this;
		while(n.next!=null) {
			n = n.next;
			num ++;
		}
		return num;
	}
}
