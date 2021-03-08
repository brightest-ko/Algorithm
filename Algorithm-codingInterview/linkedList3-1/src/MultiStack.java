import java.util.EmptyStackException;

public class MultiStack {
	//StackInfo는 각 스택에 대한 자료를 들고 있는 간단한 클래스이다.
	//스택의 실제 아이템을 들고 있지는 않는다. 개별적인 변수 다발을 사용해서
	//실제 아이템을 들고 있게 할 수 있지만, 이 방법은 굉장히 지저분하고
	//실제로 이렇게 해서 얻을 수 있는 게 많지 않다.
	
	private class StackInfo{
		public int start, size, capacity;
		public StackInfo(int start, int capacity) {
			this.start = start;
			this.capacity = capacity;
		}
		
		//주어진 배열 내의 인덱스가 스택의 구역 내에 있는지 확인한다.
		//스택은 순환해서 배열의 시작 지점으로 옮겨갈 수도 있다.
		public boolean isWidthinStackCapacity(int index) {
			//배열의 범위를 벗어나면 false를 반환한다.
			if (index < 0 || index >= values.length) {
				return false;
			}
			
			//인덱스가 배열을 순환해야 한다면 그 값을 알맞게 고쳐준다.
			int contiguousIndex = index < start ? index + values.length :  index;
			int end = start + capacity;
			return start <= contiguousIndex && contiguousIndex < end;
		}
		
		public int lastCapacityIndex() {
			return adjustIndex(start + capacity - 1);
		}
		
		public int lastElementIndex() {
			return adjustIndex(start + size - 1);
		}

		public boolean isFull() {
			return size == capacity;
		}

		public boolean isEmpty() {
			return size == 0;
		}
	}
	
	private StackInfo[] info;
	private int[] values;
	
	public MultiStack(int numberOfStack, int defaultSize) {
		//모든 스택에 대한 메타데이터를 만든다.
		info = new StackInfo[numberOfStack];
		for (int i = 0; i < numberOfStack; i++) {
			info[i] = new StackInfo(defaultSize * i, defaultSize);
		}
		values = new int[numberOfStack* defaultSize];
	}
	
//	//모든 스택이 꽉 찬 경우를 대비해서 예외 처리를 해준다.
//	public void push(int stackNum, int value) throws FullStackException{
//		if(allStackAreFull()) {
//			throw new FullStackException();
//		}
//		
//		//스택 포인터를 증가시키고 가장 꼭대기 값을 갱신한다.
//		sizes[stackNum]++;
//		values[indexOfTop(stackNum)] = value;
//	}
//	
//	//스택에서 값을 꺼낸다.
//	public int pop(int stackNum) {
//		//여유 공간이 있는지 검사한다.
//		if(isEmpty(stackNum)) {
//			throw new EmptyStackException();
//		}
//		
//		int topIndex = indexOfTop(stackNum);
//		int value = values[topIndex]; //가장 꼭대기 값을 꺼낸다.
//		values[topIndex] = 0; //꼭대기 값을 지운다.
//		sizes[stackNum]--; //스택의 크기를 줄인다.
//		return value;
//	}
//	
//	//꼭대기 원소를 반환한다.
//	public int peek(int stackNum) {
//		if(isEmpty(stackNum)) {
//			throw new EmptyStackException();
//		}
//		return values[indexOfTop(stackNum)];
//	}
//	

}
