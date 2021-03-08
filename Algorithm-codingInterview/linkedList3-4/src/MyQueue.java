import java.util.NoSuchElementException;
import java.util.Stack;

public class MyQueue {
	Stack stackNewest, stackOldest;
	
	public MyQueue() {
		stackNewest = new Stack();
		stackOldest = new Stack();
	}
	
	public int size() {
		return stackNewest.size()+stackOldest.size();
	}
	
	public void add(int value) {
		//새로운 원소가 상단에 놓이도록 stackNewest에 원소를 삽입한다.
		stackNewest.push(value);
	}
	
	//stackNewest에서 stackOldest로 원소를 옮긴다.
	//stackOldest 여산을 수행하기 위한 작업이다.
	private void shiftStacks() {
		if(stackOldest.isEmpty()) {
			while(!stackNewest.isEmpty()) {
				stackOldest.push(stackNewest.pop());
			}
		}
	}
	
	public int peek() {
		shiftStacks(); //stackOldest에 현재 원소들이 들어있다.
		return (int) stackOldest.peek(); //가장 오래된 원소를 반환한다.
	}
	
	public int remove() {
		shiftStacks(); //stackOldest에 현재 원소들이 들어있다.
		return (int) stackOldest.pop(); //가장 오래된 원소를 반환한다.
	}

	public static void main(String args[]) {
		MyQueue li = new MyQueue();
		System.out.println(li.size());
		li.add(1);
		li.add(2);
		li.add(3);
		li.add(4);
		li.add(5);
		System.out.println(li.size());
		System.out.println(li.stackNewest);
		System.out.println(li.stackOldest);
		
		li.shiftStacks();
		System.out.println(li.stackNewest);
		System.out.println(li.stackOldest);
		li.shiftStacks();
		System.out.println(li.stackNewest);
		System.out.println(li.stackOldest);

		System.out.println(li.peek());
		li.remove();
		System.out.println(li.peek());
	}	

}
