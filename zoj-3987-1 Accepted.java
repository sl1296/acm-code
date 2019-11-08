
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static Scanner in = new Scanner(System.in);
	static BigInteger xp[] = new BigInteger[20010];
	static BigInteger two = BigInteger.valueOf(2);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int ca = in.nextInt();
		while(ca-->0) {
			BigInteger n = in.nextBigInteger();
			BigInteger m = in.nextBigInteger();
			xp[0]=BigInteger.ONE;
			for(int i=1;;i++) {
				xp[i] = xp[i-1].multiply(two);
				if(xp[i].compareTo(n)>=0) break;
			}
			BigInteger ans = BigInteger.ZERO;
			while(n.compareTo(BigInteger.ZERO)>0) {
				BigInteger k = n.divide(m);
				BigInteger y = n.mod(m);
				if(y.compareTo(BigInteger.ZERO)==0||!k.testBit(0)) {
					 ans = ans.add(k);
					 if(y.compareTo(BigInteger.ZERO)!=0) ans = ans.add(BigInteger.ONE);
					 break;
				}else {
					ans = ans.add(k).add(BigInteger.ONE);
					int cnt=0;
					for(int i=0;k.testBit(i);i++) cnt++;
					n = (xp[cnt].subtract(BigInteger.ONE)).multiply(m).add(y);
					n = n.mod(xp[cnt]);
				}
			}
			System.out.println(ans);
		}
	}
}

