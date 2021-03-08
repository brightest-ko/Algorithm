//해법#1.뒤집어서 비교한다.
public class IsPalindromeClass {

	boolean isPalindrome(LinkedListNode head) {
		LinkedListNode reversed = reverseAndClone(head);
		return isEqual(head, reversed);
	}
	
	LinkedListNode reverseAndClone(LinkedListNode node) {
		LinkedListNode head = null;
		while(node != null) {
			LinkedListNode n = new LinkedListNode(node.data); // 복
			n.next = head;
			head = n;
			node = node.next;
		}
		return head;
	}
	
	boolean isEqual(LinkedListNode one, LinkedListNode two) {
		while(one != null && two != null) {
			if(one.data != two.data) {
				return false;
			}
			one = one.next;
			two = two.next;
		}
		return one == null && two == null;
	}
	
	public static void main(String args[]) {
		IsPalindromeClass li = new IsPalindromeClass();
		LinkedListNode l1 = new LinkedListNode(7);
		l1.appendToTail(1);
		l1.appendToTail(1);
		l1.appendToTail(7);
		
		System.out.println(li.isPalindrome(l1));
	}	
}
