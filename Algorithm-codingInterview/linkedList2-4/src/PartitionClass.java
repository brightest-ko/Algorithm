public class PartitionClass {
	
	LinkedListNode patition(LinkedListNode node, int x) {
		LinkedListNode beforeStart = null;
		LinkedListNode beforeEnd = null;
		LinkedListNode afterStart = null;
		LinkedListNode afterEnd = null;
		
		//리스트를 분할한다.
		while(node != null) {
			LinkedListNode next = node.next;
			node.next = null;
			if(node.data<x) {
				//before 리스트의 끝에 원소를 삽입한다.
				if(beforeStart==null) {
					beforeStart = node;
					beforeEnd = beforeStart;
				}else {
					beforeEnd.next = node;
					beforeEnd = node;
				}
			}else {
				//after 리스트의 끝에 원소를 삽입한다.
				if(afterStart==null) {
					afterStart = node;
					afterEnd = afterStart;
				}else {
					afterEnd.next = node;
					afterEnd = node;
				}
			}
			node = next;
		}	
		if(beforeStart == null) {
			return afterStart;
		}
		//before와 after를 병합한다.
		beforeEnd.next = afterStart;
		return beforeStart;
	}
	
	LinkedListNode patition2(LinkedListNode node, int x) {
		LinkedListNode head = node;
		LinkedListNode tail = node;
		
		while(node!=null) {
			LinkedListNode next = node.next;
			if(node.data < x) {
				//head에 노드를 삽입한다.
				node.next = head;
				head = node;
			}else {
				//tail에 노드를 삽입한다.
				tail.next = node;
				tail = node;
			}
			node = next;
		}
		tail.next = null;
		
		// head가 바뀌었기 때문에 새로운 head를 반환해야 한다.
		return head;
	}
	public static void main(String args[]) {
		PartitionClass li = new PartitionClass();
		LinkedListNode n = new LinkedListNode(3);
		n.appendToTail(5);
		n.appendToTail(8);
		n.appendToTail(10);
		n.appendToTail(2);
		n.appendToTail(1);

		li.patition(n,5);
		li.patition2(n,5);
		
		while(n!=null) {
			System.out.println(n.data);
			n = n.next;
		}
	}	
}
