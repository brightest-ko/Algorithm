
public class Caesar {
	int cn = (int)'z'-(int)'a'+1;
	
	int goletter(int nl,char c) {
		if(Character.isLowerCase(c)) {
			while(!Character.isLowerCase((char)nl)) 
				nl = nl - cn;
		}
		else if(Character.isUpperCase(c)) {
			while(!Character.isUpperCase((char)nl)) 
				nl = nl - cn;
		}
		return nl;
	}
	
	String caesar(String s, int n) {
		String result = "";
		int len_s = s.length();
		for(int i=0;i<len_s;i++) {
			char c = s.charAt(i);
			int nl = (int)c + n;
			if(c==' ') {
				result+=" ";
			}else if((Character.isLowerCase(c)&&!Character.isLowerCase((char)nl)) || (Character.isUpperCase(c)&&!Character.isUpperCase((char)nl))) {
				result += (char)goletter(nl,c);
			}else {
	            result += (char)nl;
			}
		}
	    return result;
	}

	public static void main(String[] args) {
		Caesar c = new Caesar();
		System.out.println(c.caesar("a B z", 4));
	}

}
