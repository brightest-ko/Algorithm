import java.util.LinkedList;
import java.util.Stack;

public class AnimalQueue {
	LinkedList dogs = new LinkedList();
	LinkedList cats = new LinkedList();
	private int order = 0; // timestamp의 역활을 한다.
	
	public void enqueue(Animal a) {
		//개와 고야이의 수용 순서를 비교하기 위해 timestamp를 사용해서 이들의 순서를 정한다.
		a.setOrder(order);
		order++;
		if(a instanceof Dog) dogs.addLast((Dog) a);
		else if(a instanceof Cat) cats.addLast((Cat) a);
	}
	public Animal dequeueAny() {
		//개와 고양이 큐의 맨 앞을 살펴본 뒤
		//그 중 더 오래전에 들어온 동물을 큐에서 빼낸다.
		if(dogs.size() == 0) {
			return dequeueCats();
		}else if(cats.size()==0) {
			return dequeueDogs();
		}
		Dog dog = (Dog) dogs.peek();
		Cat cat = (Cat) cats.peek();
		if(dog.isOlderThan(cat)) {
			return dequeueDogs();			
		}else {
			return dequeueCats();		
		}
	}
	public Dog dequeueDogs() {
		return (Dog) dogs.poll();
	}
	public Cat dequeueCats() {
		return (Cat) cats.poll();
	}
	public static void main(String args[]) {
		AnimalQueue li = new AnimalQueue();

		Dog d1 = new Dog("뽀미");
		Dog d2 = new Dog("까망이");
		Dog d3 = new Dog("초코");
		
		Cat c1 = new Cat("냐옹");
		Cat c2 = new Cat("나비");
		Cat c3 = new Cat("순무");

		li.enqueue(d1);
		li.enqueue(d2);
		li.enqueue(c1);
		li.enqueue(d3);
		li.enqueue(c2);
		li.enqueue(c3);
		System.out.println(li.dequeueDogs().name);
		System.out.println(li.dequeueCats().name);
		System.out.println(li.dequeueAny().name);
		
	}	

}
