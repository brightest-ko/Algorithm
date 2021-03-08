import java.util.Stack;

//해법#3.재귀적 접근
public class IsPalindromeClass3 {

	class Result{
		public LinkedListNode node;
		public boolean result;

		public Result(LinkedListNode node, boolean result) {
			this.node = node;
			this.result = result;
		}
	}
	
	boolean isPalindrome(LinkedListNode head) {
		int length = lengthOfList(head);
		Result p =isPalindromeRecurse(head,length);
		return p.result;
	}

	Result isPalindromeRecurse(LinkedListNode head, int length) {
		if(head == null || length <= 0){ //노드의 개수가 홀수일 때
			System.out.println(head.data);
			return new Result(head,true);
		}else if(length == 1) { // 노드의 개수가 홀수일 때
			return new Result(head.next,true);
		}
		
		//부분 리스트를 재귀적으로 호출한다.
		Result res = isPalindromeRecurse(head.next, length-2);
	
		//아래 호출 결과 회문이 아니라는 사실이 밝혀지면, 그 결과값을 반환한다.
		if(!res.result || res.node == null) {
			return res;
		}
		
		//두 노드의 값이 같은지 확인한다.
		res.result = (head.data == res.node.data);
		
		//그 다음에 비교할 노드를 반환한다.
		res.node = res.node.next;
		
		return res;
	}
	
	int lengthOfList(LinkedListNode n) {
		int size = 0;
		while(n!=null) {
			size ++;
			n = n.next;
		}
		return size;
	}
	
	public static void main(String args[]) {
		IsPalindromeClass3 li = new IsPalindromeClass3();
		LinkedListNode l1 = new LinkedListNode(7);
		l1.appendToTail(1);
		l1.appendToTail(1);
		l1.appendToTail(7);
		
		System.out.println(li.isPalindrome(l1));
	}	
}
