
public class AddListsClass2 {

	class PartialSum{
		public LinkedListNode sum = null;
		public int carry = 0;
	}
	
	LinkedListNode addLists(LinkedListNode l1, LinkedListNode l2) {
		int len1 = l1.length();
		int len2 = l2.length();
		
		//짧은 리스트에 0을 붙인다. 본문의 1. 설명확인
		if(len1<len2) {
			l1 = padList(l1, len2-len1);
		} else {
			l2 = padList(l2, len1-len2);
		}
		
		//두 리스트를 더한다.
		PartialSum sum = addListsHelper(l1, l2);
		
		//넘김수(carry)가 존재한다면 리스트의 앞쪽에 삽입한다.
		//그렇지 않다면 연결리스트만 변형한다.
		if(sum.carry == 0) {
			return sum.sum;
		}else {
			LinkedListNode result = insertBefore(sum.sum, sum.carry);
			return result;
		}
	}
	
	PartialSum addListsHelper(LinkedListNode l1, LinkedListNode l2) {
		if(l1 == null && l2 == null) {
			PartialSum sum = new PartialSum();
			return sum;
		}
		//작은 자릿수를 재귀적으로 더한다.
		PartialSum sum = addListsHelper(l1.next, l2.next);

		//현재 값에 넘김수를 더한다.
		int val = sum.carry + l1.data + l2.data;
		
		//현재 자릿수를 합한 결과를 삽입한다.
		LinkedListNode full_result = insertBefore(sum.sum, val % 10);
		
		//지금까지의 합과 넘김수를 반환한다.
		sum.sum = full_result;
		sum.carry = val / 10;
		return sum;
	}
	
	LinkedListNode padList(LinkedListNode l, int padding) {
		LinkedListNode head = l;
		for(int i = 0;i<padding;i++) {
			head = insertBefore(head,0);
		}
		return head;
	}
	
	//연결리스트 앞에 노드를 삽입하기 위한 도움 함수
	LinkedListNode insertBefore(LinkedListNode list, int data) {
		LinkedListNode node = new LinkedListNode(data);
		if(list != null) {
			node.next = list;
		}
		return node;
	}
	public static void main(String[] args) {
		AddListsClass2 li = new AddListsClass2();
		LinkedListNode l1 = new LinkedListNode(1);
		LinkedListNode l2 = new LinkedListNode(5);
		l1.appendToTail(2);
		l1.appendToTail(3);
		l1.appendToTail(4);
		l2.appendToTail(6);
		l2.appendToTail(7);

		LinkedListNode n = li.addLists(l1, l2);
		while(n!=null) {
			System.out.println(n.data);
			n = n.next;
		}
		//1234+567 = 1801
	}

}
