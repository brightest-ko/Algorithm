
public class Animal {
	private int order;
	protected String name;
	public Animal(String n) {name = n;}
	public void setOrder(int ord) {
		order = ord;
	}
	public int getOrder() {
		return order;
	}
	//오래된 동물을 반환하기 위해서 순서 비교하기
	public boolean isOlderThan(Animal a) {
		return this.order < a.getOrder();
	}
}
