import java.util.Stack;

//해법#2.순환적 접근
public class IsPalindromeClass2 {

	boolean isPalindrome(LinkedListNode head) {
		LinkedListNode fast = head;
		LinkedListNode slow = head;
		
		Stack<Integer> stack = new Stack<Integer>();
		
		//연결리스트의 앞 절반을 스택에 쌓는다. fast runner(2배 빠른)가
		//연결리스트의 끝에 도달하면, slow runner가 중간에 도달했다는 사실을 알 수 있다.
		while(fast != null && fast.next != null) {
			stack.push(slow.data);
			slow = slow.next;
			fast = fast.next.next;
		}
		
		//월소의 개수가 홀수 개라면 가운데 원소는 넘긴다.
		if(fast != null) {
			slow = slow.next;
		}
		
		while(slow != null) {
			int top = stack.pop().intValue();
			//값이 다르면 회문이 될 수 없다.
			if(top != slow.data) {
				return false;
			}
			slow = slow.next;
		}
		return true;
	}
	
	public static void main(String args[]) {
		IsPalindromeClass2 li = new IsPalindromeClass2();
		LinkedListNode l1 = new LinkedListNode(7);
		l1.appendToTail(1);
		l1.appendToTail(1);
		l1.appendToTail(7);
		
		System.out.println(li.isPalindrome(l1));
	}	
}
