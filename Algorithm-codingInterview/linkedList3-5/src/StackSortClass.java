import java.util.Stack;

public class StackSortClass {
	void sort(Stack s) {
		Stack r = new Stack();
		while(!s.isEmpty()) {
			//s의 원소를 정렬된 순서로 r에 삽입한다.
			int tmp = (int) s.pop();
			System.out.println(tmp);
			while(!r.isEmpty()&& (int)r.peek() >tmp) {
				s.push(r.pop());
			}
			r.push(tmp);
		}	
		
		//r에서 s로 원소를 다시 옮겨준다.
		while(!r.isEmpty()) {
			s.push(r.pop());
		}
	}
	public static void main(String args[]) {
		StackSortClass li = new StackSortClass();
		Stack s = new Stack();
		s.push(1);
		s.push(7);
		s.push(5);
		s.push(2);
		s.push(3);
		li.sort(s);
		System.out.println();
		while(!s.isEmpty()) {
			System.out.println(s.pop());
		}
	}	

}
