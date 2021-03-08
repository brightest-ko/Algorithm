import java.util.Arrays;

class NoOvertime {
	public int noOvertime(int no, int[] works) {
		int result = 0;
		int l  = works.length - 1; //가장 마지막
		for(int i =0; i < no ;i++) {
			Arrays.sort(works); //정렬시켜
			works[l] = works[l]-1; //가장 큰 값을 하나씩 뺀다.
		}
		for(int i =0;i<works.length;i++) {
			result += Math.pow(works[i],2);
		}
		return result;
	}
	public static void main(String[] args) {
		NoOvertime c = new NoOvertime();
		int []test = {4,3,3};
		System.out.println(c.noOvertime(4,test));
	}
}
