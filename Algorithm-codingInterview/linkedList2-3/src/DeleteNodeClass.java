public class DeleteNodeClass {
	boolean  deleteNode(LinkedListNode n) {
		if( n == null || n.next == null ) {
			return false; // 실패.
		}
		LinkedListNode next = n.next;
		n.data = next.data;
		n.next = next.next;
		return true;
		
	}
	
	public static void main(String args[]) {
		DeleteNodeClass li = new DeleteNodeClass();
		LinkedListNode n = new LinkedListNode(2);
		n.appendToTail(2);
		n.appendToTail(3);
		n.appendToTail(4);
		
		li.deleteNode(n.next.next);
		//li.deleteNode(n.next.next.next); // 가장마지막거를 지우려면 어떻게 해야하지?
		
		while(n!=null) {
			System.out.println(n.data);
			n = n.next;
		}
	}	
}
