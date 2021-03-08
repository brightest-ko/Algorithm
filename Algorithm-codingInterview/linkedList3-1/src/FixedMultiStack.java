import java.util.EmptyStackException;

public class FixedMultiStack {
	
	private int numberOfStack = 3;
	private int stackCapacity;
	private int[] values;
	private int[] sizes;
	
	public FixedMultiStack(int stackSize) {
		stackSize = stackSize;
		values = new int[stackSize* numberOfStack];
		sizes = new int[numberOfStack];
	}
	
	//스택에 값을 추가한다.
	public void push(int stackNum, int value) throws FullStackException{
		//여유 공간이 있는지 검사한다.
		if(isFull(stackNum)) {
			throw new FullStackException();
		}
		
		//스택 포인터를 증가시키고 가장 꼭대기 값을 갱신한다.
		sizes[stackNum]++;
		values[indexOfTop(stackNum)] = value;
	}
	
	//스택에서 값을 꺼낸다.
	public int pop(int stackNum) {
		//여유 공간이 있는지 검사한다.
		if(isEmpty(stackNum)) {
			throw new EmptyStackException();
		}
		
		int topIndex = indexOfTop(stackNum);
		int value = values[topIndex]; //가장 꼭대기 값을 꺼낸다.
		values[topIndex] = 0; //꼭대기 값을 지운다.
		sizes[stackNum]--; //스택의 크기를 줄인다.
		return value;
	}
	
	//꼭대기 원소를 반환한다.
	public int peek(int stackNum) {
		if(isEmpty(stackNum)) {
			throw new EmptyStackException();
		}
		return values[indexOfTop(stackNum)];
	}
	
	//스택이 비어 있으면 true를 반환한다.
	public boolean isEmpty(int stackNum) {
		return sizes[stackNum] == 0;
	}

	//스택이 꽉  있으면 true를 반환한다.
	public boolean isFull(int stackNum) {
		return sizes[stackNum] == stackCapacity;
	}
	
	//스택의 꼭대기 값을 가리키는 인덱스를 반환한다.
	private int indexOfTop(int stackNum) {
		int offset = stackNum *  stackCapacity;
		int size = sizes[stackNum];
		return offset + size - 1;
	}
}
