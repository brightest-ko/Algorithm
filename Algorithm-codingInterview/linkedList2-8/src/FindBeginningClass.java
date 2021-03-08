public class FindBeginningClass {

	LinkedListNode findBeginning(LinkedListNode head ) {
		LinkedListNode slow = head;
		LinkedListNode fast = head;
		
		//만나는 지점을 찾는다. 연결리스트 안에서 LOOP-SIZE-k 만큰 들어간 상태이다.
		while(fast != null  && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;
			if(slow == fast) {
				//충돌
				break;
			}
		}
		
		//에러 체크. 만나는 지점이 없다면 루프도 없다.
		if(fast == null || fast.next == null) {
			return null;
		}
		
		//slow를 head로 옮기고, fast는 그대로 둔다. 이 둘은 루프 시작 지점에서 k만큼 떨어져 있다. 이 둘이 같은 속도로 움직인다면 시작 지점에서 만나게 된다.
		slow = head;
		while(slow != fast) {
			slow = slow.next;
			fast = fast.next;
		}
		
		//둘 다 루프의 시작 지점을 가리킨다.
		return fast;
	}
	
	public static void main(String args[]) {
		FindBeginningClass li = new FindBeginningClass();
		LinkedListNode l1 = new LinkedListNode(1);
		l1.appendToTail(2);
		l1.appendToTail(3);
		l1.appendToTail(4);
		l1.appendToTail(5);
		l1.next.next.next.next.next = l1.next.next;
		
		LinkedListNode list = li.findBeginning(l1);
		System.out.println(list.data);
	}	
}
