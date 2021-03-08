public class Pktl {
	//해법 #2 : 재귀적 방법.
	//k번쨰 원소의 값을 '출력'하도록 바꿈.카운터값만 반환.
	int printKthToLast(LinkedListNode head, int k){
		if(head == null) {
			return 0;
		}
		int index = printKthToLast(head.next,k)+1;
		if(index == k) {
			System.out.println(k+"th to last node is"+head.data);
		}
		System.out.println(index +" "+ k);
		return index;
	}

	//해법 #3 : 순환 방법.
	//
	LinkedListNode printKthToLast2(LinkedListNode head, int k){
		LinkedListNode p1 = head;
		LinkedListNode p2 = head;
		
		//p1을 k노드만큼 이동시킨다.
		for(int i=0;i<k;i++) {
			if(p1 == null) return null; // out of bounds.
			p1 = p1.next;
		}
		
		//p1과 p2를 함께 움직인다. p1이 끝에 도달하면, p2는 length-k번째 원소를 가르키게 된다.
		while(p1 != null) {
			p1 = p1.next;
			p2 = p2.next;
		}
		return p2;
	}
	
	public static void main(String[] args) {
		Pktl p = new Pktl();
		LinkedListNode n = new LinkedListNode(77);
		n.appendToTail(90);
		n.appendToTail(80);
		n.appendToTail(88);
		System.out.println(p.printKthToLast(n,2));
		System.out.println(p.printKthToLast2(n,2).data);
	}

}
