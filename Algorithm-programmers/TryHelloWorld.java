
public class TryHelloWorld {

    public int countOne(int n)
    {
        int count = 0;
        int nn = n;
        for(int i =0;i < (int)(Math.log(nn)/Math.log(2)) + 1;i++) {
        	count += n % 2;
        	n = n / 2;
        }
        return count;
    }
    public int nextBigNumber(int n)
    {
        int answer = 0;
        int i = 0;
        while(true) {
        	i = i+1;
        	if(countOne(n+i) == countOne(n))
        		break;
        }
        answer = n+i;
        return answer;
    }
    public static void main(String[] args)
    {
        TryHelloWorld test = new TryHelloWorld();
        int n = 78;
        System.out.println(test.nextBigNumber(n));
    }

}
