public class AddListsClass {
	
	LinkedListNode addLists(LinkedListNode l1, LinkedListNode l2, int carry) {
		if(l1 == null && l2 == null && carry ==0) {
			return null;
		}
		
		LinkedListNode result = new LinkedListNode(0);
		int value = carry;
		if(l1 != null) {
			value += l1.data;
		}
		if(l2 != null) {
			value += l2.data;
		}
		
		result.data = value % 10; //두번째 숫자
		//재귀
		if(l1 != null || l2 != null) {
			LinkedListNode more = addLists(l1 == null? null:l1.next,l2 == null? null:l2.next,value >= 10? 1:0);
			result.next = more;
		}
		return result;
	}
	
	public static void main(String args[]) {
		AddListsClass li = new AddListsClass();
		LinkedListNode l1 = new LinkedListNode(7);
		LinkedListNode l2 = new LinkedListNode(5);
		//l1.appendToTail(7);
		l1.appendToTail(1);
		l1.appendToTail(6);
		//l2.appendToTail(5);
		l2.appendToTail(9);
		l2.appendToTail(2);

		LinkedListNode n = li.addLists(l1, l2, 0);
		while(n!=null) {
			System.out.println(n.data);
			n = n.next;
		}
	}	
}
