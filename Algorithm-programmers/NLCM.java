import java.util.Arrays;

public class NLCM {

	public long lcm(long[] num) {
		Arrays.sort(num);
		System.out.println(num[0]+" "+num[1]);
		for(long i = num[0] ; i > 1 ; i--) {
			if(num[0] % i == 0 && num[1] % i == 0) {
				System.out.println(i*(num[0]/i)*(num[1]/i));
	            return i*(num[0]/i)*(num[1]/i);
	        }
		}
		return num[0]*num[1];
	}
	
	public long nlcm(int[] num) {
		long[] a = {num[0],num[1]};
		long answer = lcm(a);
		if( num.length > 2 ) {
			for(int i=2;i<num.length;i++) {
				long[] b = {answer,num[i]};
				answer = lcm(b);
			}
		}
		return answer;
	}
/*
 
 public long gcd(long a,long b){
 if(a>b)
 return (a%b==0)? b:gcd(b,a%b);
 else
 return (b%a==0)? a:gcd(a,b%a);
 }
 */
    
	public static void main(String[] args) {
		NLCM c = new NLCM();
		int[] ex = { 2, 6, 8, 14 };
		// 아래는 테스트로 출력해 보기 위한 코드입니다.
		System.out.println(c.nlcm(ex));
	}

}
