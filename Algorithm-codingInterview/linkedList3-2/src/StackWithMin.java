import java.util.Stack;

public class StackWithMin extends Stack {
	
	public void push(int value) {
		int newMin = Math.min(value, min());
		super.push(new NodeWithMin(value, newMin));
	}

	public int min() {
		if (this.isEmpty()) {
			return Integer.MAX_VALUE; // 에러
		} else {
			return peek().min;
		}
	}

	public static void main(String args[]) {
		StackWithMin li = new StackWithMin();
		li.push(3);
		li.push(4);
		li.push(2);
		li.push(6);
		
		System.out.println(li.min());
	}	
}

class NodeWithMin {
	public int value;
	public int min;

	public NodeWithMin(int v, int min) {
		value = v;
		this.min = min;
	}
}
