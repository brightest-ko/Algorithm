public class JumpCase {

//자료형의 한계로 불가능
    public static double fac(int a) {
    	if(a<=1)
    		return 1;
    	else
    		return a*fac(a-1);
    }
    public double com(int a,int b) {
        return fac(a)/(fac(b)*fac(a-b));
    }
    public int jumpCase(int num) {
        int answer = 0;
        int n = num/2+1;
        for(int i =0;i < n ; i++ ) {
        	System.out.println(num+" "+i+" "+com(num,i));
        	answer += com(num,i);
        	num = num-1;
        	System.out.println(i+" "+answer);
        }
        return answer;
    }

/*
    public int jumpCase(int num) {
    	if(num==1)
    		return 1;
    	else if (num == 2)
    		return 2;
    	return jumpCase(num-1)+jumpCase(num-2);
    }
*/
	public static void main(String[] args) {
    	JumpCase c = new JumpCase();
        int testCase = 17;
        //아래는 테스트로 출력해 보기 위한 코드입니다.
        //System.out.println(fac(34)+" "+fac(1)+" "+fac(15)+" "+fac(16)/fac(15));
        System.out.println(c.jumpCase(testCase));
    }

}