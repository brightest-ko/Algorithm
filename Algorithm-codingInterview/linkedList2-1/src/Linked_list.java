import java.util.HashSet;

public class Linked_list {
	void  deleteDups(LinkedListNode n) {
		HashSet set = new HashSet();
		LinkedListNode previous = null;
		while( n!= null ) {
			if(set.contains(n.data)) {
				previous.next = n.next;
			}else {
				set.add(n.data);
				previous = n;
			}
			n = n.next;
		}
		
	}
	void  deleteDups2(LinkedListNode head) {
		LinkedListNode current = head;
		while(current != null) {
			LinkedListNode runner = current;
			while(runner.next != null) {
				if (runner.next.data == current.data) {
					runner.next = runner.next.next;
				}else {
					runner = runner.next;
				}
			}
			current = current.next;
		}
	}
	
	public static void main(String args[]) {
		Linked_list li = new Linked_list();
		LinkedListNode n = new LinkedListNode(2);
		n.appendToTail(2);
		n.appendToTail(3);
		n.appendToTail(4);
		//li.deleteDups(n);
		li.deleteDups(n);
		
		LinkedListNode now = n;
		while(n!=null) {
			System.out.println(n.data);
			n = n.next;
		}
	}	
}
