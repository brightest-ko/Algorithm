import java.util.Stack;

public class StackWithMin2 extends Stack{
	Stack s2;
	
	public StackWithMin2() {
		s2 = new Stack();
	}
	
	public void push(int value) {
		if (value <= min()) {
			s2.push(value);
		}
		super.push(value);
	}
	
	public Integer pop() {
		int value = (int) super.pop();
		if(value == min()) {
			s2.pop();
		}
		return value;
	}
	
	public int min() {
		if(s2.isEmpty()) {
			return Integer.MAX_VALUE;
		}else {
			return (int) s2.peek();
		}
	}

	public static void main(String args[]) {
		StackWithMin2 li = new StackWithMin2();
		li.push(3);
		li.push(4);
		li.push(2);
		li.push(6);
		
		
		System.out.println(li.min());
	}	
}
